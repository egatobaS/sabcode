#include "main.h"

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

void PrintRegister()
{
	printf("r00: 0x%016I64X r01: 0x%016I64X r02: 0x%016I64X r03: 0x%016I64X\n", r[0], r[1], r[2], r[3]);
	printf("r04: 0x%016I64X r05: 0x%016I64X r06: 0x%016I64X r07: 0x%016I64X\n", r[4], r[5], r[6], r[7]);
	printf("r08: 0x%016I64X r09: 0x%016I64X r10: 0x%016I64X r11: 0x%016I64X\n", r[8], r[9], r[10], r[11]);
	printf("r12: 0x%016I64X r13: 0x%016I64X r14: 0x%016I64X r15: 0x%016I64X\n", r[12], r[13], r[14], r[15]);
	printf("r16: 0x%016I64X r17: 0x%016I64X r18: 0x%016I64X r19: 0x%016I64X\n", r[16], r[17], r[18], r[19]);
	printf("r20: 0x%016I64X r21: 0x%016I64X r22: 0x%016I64X r23: 0x%016I64X\n", r[20], r[21], r[22], r[23]);
	printf("r24: 0x%016I64X r25: 0x%016I64X r26: 0x%016I64X r27: 0x%016I64X\n", r[24], r[25], r[26], r[27]);
	printf("r28: 0x%016I64X r29: 0x%016I64X r30: 0x%016I64X r31: 0x%016I64X\n", r[28], r[29], r[30], r[31]);
}

bool CWriteFile(const char* FilePath, const void* Data, unsigned int Size)
{
	HANDLE fHandle = CreateFile(FilePath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fHandle == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	DWORD writeSize = Size;
	if (WriteFile(fHandle, Data, writeSize, &writeSize, NULL) != TRUE) {
		return FALSE;
	}
	CloseHandle(fHandle);
	return TRUE;
}

bool CReadFile(const char* FileName, MemoryBuffer &pBuffer)
{
	HANDLE hFile;  DWORD dwFileSize, dwNumberOfBytesRead;
	hFile = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	dwFileSize = GetFileSize(hFile, NULL);
	unsigned char* lpBuffer = (unsigned char*)malloc(dwFileSize);
	if (lpBuffer == NULL) {
		CloseHandle(hFile);
		return FALSE;
	}

	if (ReadFile(hFile, lpBuffer, dwFileSize, &dwNumberOfBytesRead, NULL) == FALSE) {
		free(lpBuffer);
		CloseHandle(hFile);
		return FALSE;
	}
	else if (dwNumberOfBytesRead != dwFileSize) {
		free(lpBuffer);
		CloseHandle(hFile);
		return FALSE;
	}

	CloseHandle(hFile);
	pBuffer.Add(lpBuffer, dwFileSize);
	free(lpBuffer);
	return TRUE;
}