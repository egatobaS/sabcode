#pragma once

class MemoryBuffer
{

public:
	MemoryBuffer(DWORD dwSize = 512) {
		m_pBuffer = NULL;
		m_dwDataLength = 0;
		m_dwBufferSize = 0;

		if ((dwSize < UINT_MAX) && (dwSize != 0)) {
			m_pBuffer = (BYTE*)malloc(dwSize + 1);    // one more char, in case when using string funcions
			if (m_pBuffer) {
				m_dwBufferSize = dwSize;
				m_pBuffer[0] = 0;
			}
		}
	};

	~MemoryBuffer() {
		if (m_pBuffer) free(m_pBuffer);

		m_pBuffer = NULL;
		m_dwDataLength = 0;
		m_dwBufferSize = 0;
	};

	// Add chunk of memory to buffer
	BOOL Add(CONST PVOID p, DWORD dwSize) {
		if (CheckSize(dwSize)) {
			memcpy(m_pBuffer + m_dwDataLength, p, dwSize);
			m_dwDataLength += dwSize;
			*(m_pBuffer + m_dwDataLength) = 0;    // fill end zero
			return TRUE;
		}
		else {
			return FALSE;
		}
	};

	// Get the data in buffer
	PBYTE GetData() CONST {
		return m_pBuffer;
	};

	// Get the length of data in buffer
	DWORD GetDataLength() CONST {
		return m_dwDataLength;
	};

	// Rewind the data pointer to the begining
	VOID Rewind() {
		m_dwDataLength = 0; m_pBuffer[0] = 0;
	};

	// Automatically adjust increase buffer size if necessary
	BOOL CheckSize(DWORD dwSize) {
		if (m_dwBufferSize >= (m_dwDataLength + dwSize)) {
			return TRUE;    // Enough space
		}
		else {
			// Try to double it
			DWORD dwNewSize = max(m_dwDataLength + dwSize, m_dwBufferSize * 2);
			BYTE* pNewBuffer = (PUCHAR)realloc(m_pBuffer, dwNewSize + 1);
			if (pNewBuffer) {
				m_pBuffer = pNewBuffer;
				m_dwBufferSize = dwNewSize;
				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	}

private:
	PBYTE m_pBuffer;
	DWORD m_dwDataLength;
	DWORD m_dwBufferSize;
};

void printBits(size_t const size, void const * const ptr);

void PrintRegister();

bool CReadFile(const char* FileName, MemoryBuffer &pBuffer);

bool CWriteFile(const char* FilePath, const void* Data, unsigned int Size);