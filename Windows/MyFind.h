#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

BOOL FindFile(std::wstring& url, std::wstring& name) {

	url += L"/";

	HANDLE hFindFile;
	WIN32_FIND_DATAW FindFileData;

	hFindFile = FindFirstFileW((url + name).c_str(), &FindFileData);

	if (hFindFile != INVALID_HANDLE_VALUE) {
		do {
			std::wcout << url << FindFileData.cFileName << std::endl;
		} while (FindNextFileW(hFindFile, &FindFileData));
	}
	
	hFindFile = FindFirstFileW((url + L"*").c_str(), &FindFileData);
	if (hFindFile == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
			return TRUE;
		else
			return FALSE;
	}

	do {
		if (lstrcmpW(FindFileData.cFileName, L".") != 0 && lstrcmpW(FindFileData.cFileName, L"..") && (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			std::wstring inUrl = url + FindFileData.cFileName;
			FindFile(inUrl, name);
		}
	} while (FindNextFileW(hFindFile, &FindFileData));

	return TRUE;
}
