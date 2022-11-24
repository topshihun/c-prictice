#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

BOOL GetDriverInfo(LPWSTR szDriver);

int main(int argc, TCHAR argv[]) {

	WCHAR szLogicalDriveStrings[1024];
	PWCHAR szDrive;

	ZeroMemory(szLogicalDriveStrings, 1024);
	GetLogicalDriveStringsW(1023, szLogicalDriveStrings);
	szDrive = (PWCHAR)szLogicalDriveStrings;

	do {
		printf("%ls\n", szDrive);
		if (!GetDriverInfo(szDrive))
			return GetLastError();
		szDrive += (lstrlen(szDrive) + 1);
	} while (*szDrive != '\0');

	return 0;

}

BOOL GetDriverInfo(LPWSTR szDriver) {


	UINT szDriverType;
	TCHAR szDriverName[MAX_PATH];
	DWORD szDriverNum;
	DWORD maxComponentLength;
	DWORD fileFlag;
	TCHAR fileSystemName[1024];

	szDriverType = GetDriveType(szDriver);

	switch (szDriverType) {
	case DRIVE_UNKNOWN:puts("The driver connot be determined."); break;
	case DRIVE_NO_ROOT_DIR:puts("The root path of the driver is invalid."); break;
	case DRIVE_REMOVABLE:puts("The driver is the type that can removable."); break;
	case DRIVE_FIXED:puts("The driver is fixed"); break;
	case DRIVE_REMOTE:puts("The driver is remote (network) driver."); break;
	case DRIVE_CDROM:puts("The driver is the CD-ROM."); break;
	case DRIVE_RAMDISK:puts("The driver is the RAM."); break;
	default:break;
	}

	if (!GetVolumeInformationW(szDriver, szDriverName, MAX_PATH, &szDriverNum, &maxComponentLength, &fileFlag, fileSystemName, 1024))
		return FALSE;

	printf("Driver name is %ls\n", szDriverName);
	printf("Volume serial number is %u\n", szDriverNum);
	printf("Maximum Compnent Length is %u\n", maxComponentLength);
	printf("System Type is %ls\n", fileSystemName);
	if (fileFlag & FILE_CASE_SENSITIVE_SEARCH)
		puts("The Volume is supported to distinguish lowercase and uppercase.");
	if (fileFlag & FILE_CASE_PRESERVED_NAMES)
		puts("The Volume can be named to lowercase and uppercase.");
	if (fileFlag & FILE_UNICODE_ON_DISK)
		puts("The Volume support to use Unicode.");
	if (fileFlag & FILE_PERSISTENT_ACLS)
		puts("The Volume have and forced to ALC.");
	if (fileFlag & FILE_FILE_COMPRESSION)
		puts("The Volume can be ziped.");
	if (fileFlag & FILE_VOLUME_QUOTAS)
		puts("The Volume can be quotas.");
	if (fileFlag & FILE_SEQUENTIAL_WRITE_ONCE)
		puts("The Volume be supported to be writted on only file.");
	puts("OVER!!!");
	
	return TRUE;
}
