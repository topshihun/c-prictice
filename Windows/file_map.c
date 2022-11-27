#include <Windows.h>
#include <stdio.h>

#define BUFFSIZE 1024
#define  FILE_MAP_START 0x28804

LPTSTR  lpcTheFile = "text.dat";

int main() {
	HANDLE hMapFile;
	HANDLE hFile;
	DWORD dByteWritten;
	DWORD dwFileSize;
	SYSTEM_INFO SysInfo;
	DWORD dwSysGran;
	DWORD dwFileMapStart;
	DWORD dwMapViewSize;
	DWORD dwFileMapSize;
	INT iViewDelta;
	LPVOID lpMapAddress;
	PCHAR pData;
	INT iData;
	BYTE cMapBuffer[32];

	hFile = CreateFile(lpcTheFile, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("Create file error:%d\n", GetLastError());
		return 1;
	}
	for (int i = 0; i < 65535; i++) {
		WriteFile(hFile, &i, sizeof(i), &dByteWritten, NULL);
	}
	dwFileSize = GetFileSize(hFile, NULL);
	printf("文件大小：%d\n", dwFileSize);

	GetSystemInfo(&SysInfo);
	dwSysGran = SysInfo.dwAllocationGranularity;

	dwFileMapStart = (FILE_MAP_START / dwSysGran) * dwSysGran;
	dwMapViewSize = (FILE_MAP_START % dwSysGran) + BUFFSIZE;
	dwFileMapSize = FILE_MAP_START + BUFFSIZE;
	iViewDelta = FILE_MAP_START - dwFileMapStart;

	hMapFile = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, dwFileMapSize, NULL);
	if (hMapFile == NULL) {
		printf("CreatFileMapping error: %d\n", GetLastError());
		return 1;
	}

	lpMapAddress = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, dwFileMapStart, dwMapViewSize);
	if (lpMapAddress == NULL) {
		printf("MapViewOfFile error: %d\n", GetLastError());
		return 1;
	}
	printf("文件map view相当于文件的起始位置: 0x%x\n", dwFileMapStart);
	printf("文件mapping对象的大小: 0x%x", dwMapViewSize);
	printf("从相对于map view 0x%x 字节的位置读取数据，", iViewDelta);

	pData = (PCHAR)lpMapAddress + iViewDelta;
	iData = *(PINT)pData;
	printf("为: 0x%.8x\n", iData);
	CopyMemory(cMapBuffer, lpMapAddress, 32);
	printf("lpMapAddress起始的字节是: ");
	for (int i = 0; i < 32; i++) {
		printf("0x%.2x ", cMapBuffer[i]);
	}
	FillMemory(lpMapAddress, 32, (BYTE)0xff);
	FlushViewOfFile(lpMapAddress, dwMapViewSize);
	printf("\n已经将lpMapAddress开始的字节使用xff填充。\n");

	if (!CloseHandle(hMapFile))
		printf("\nClosing the mapping object error %d", GetLastError());
	if(!CloseHandle(hFile))
		printf("\nError %ld occurred closing the file!", GetLastError());
	
	return 0;
}
