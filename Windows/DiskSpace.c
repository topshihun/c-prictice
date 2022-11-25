#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#define BuffLenth 1024

typedef struct Driver {
	PTCHAR pDriverString;
	DWORD lpSectorsPerCluster;
	DWORD lpBytesPerSector;
	DWORD lpNumberOfFreeClusters;
	DWORD lpTotalNumberOfClusters;
}Driver;

int main() {
	TCHAR driverString[BuffLenth];
	Driver Disk;

	Disk.pDriverString = (PTCHAR)driverString;
	
	ZeroMemory(&driverString, BuffLenth);
	GetLogicalDriveStringsW(BuffLenth, &driverString);

	Disk.pDriverString = (PTCHAR)driverString;

	do {
		if (!GetDiskFreeSpaceW(Disk.pDriverString, &Disk.lpSectorsPerCluster, &Disk.lpBytesPerSector, &Disk.lpNumberOfFreeClusters, &Disk.lpTotalNumberOfClusters))
			return GetLastError();
		printf("The Disk is %ls.\n", Disk.pDriverString);
		printf("The number of cluster sector is %u\n", Disk.lpSectorsPerCluster);
		printf("The Bytes per sector is %u\n", Disk.lpBytesPerSector);
		printf("The Number of free clusters is %u\n", Disk.lpNumberOfFreeClusters);
		printf("The Total Number of clusters is %u\n", Disk.lpTotalNumberOfClusters);
		FLOAT f = (FLOAT)Disk.lpNumberOfFreeClusters / (FLOAT)Disk.lpTotalNumberOfClusters * (FLOAT)100.0;
		printf("Thr free/total is %f\n", f);
		puts("\n");
			Disk.pDriverString += (lstrlenW(driverString) + 1);

	} while (Disk.pDriverString != '\0');
	return 0;
}
