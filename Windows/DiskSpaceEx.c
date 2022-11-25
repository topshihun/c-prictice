#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#define BuffLenth 1024

typedef struct Driver {
	PTCHAR pDriverString;
	DWORD64 lpFreeBytesAvailableToCaller;
	DWORD64 lpTotalNumberOfBytes;
	DWORD64 lpTotalNumberOfFreeBytes;
}Driver;

int main() {
	WCHAR driverString[BuffLenth];
	Driver Disk;

	Disk.pDriverString = (PTCHAR)driverString;
	
	ZeroMemory(&driverString, BuffLenth);
	GetLogicalDriveStringsW(BuffLenth, (LPWSTR)&driverString);

	Disk.pDriverString = (PTCHAR)driverString;

	do {
		if (!GetDiskFreeSpaceExW(Disk.pDriverString, (PULARGE_INTEGER)&Disk.lpFreeBytesAvailableToCaller, (PULARGE_INTEGER)&Disk.lpTotalNumberOfBytes, (PULARGE_INTEGER)&Disk.lpTotalNumberOfFreeBytes))
			return GetLastError();
		printf("The disk is %ls\n", Disk.pDriverString);
		printf("The disk free bates of caller is %llu.\n", Disk.lpFreeBytesAvailableToCaller);
		printf("The disk total of bytes is %llu.\n", Disk.lpTotalNumberOfBytes);
		printf("The disk total of free bytes is %llu.\n", Disk.lpTotalNumberOfFreeBytes);
		puts("\n");

		Disk.pDriverString += (lstrlenW(Disk.pDriverString) + 1);

	} while (Disk.pDriverString != '\0');
	return 0;
}
