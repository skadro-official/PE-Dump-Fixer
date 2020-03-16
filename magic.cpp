#include "Windows.h"

bool FixHeaderRawToVirtual(char* pLocalImage)
{
	auto pNtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uint64_t>(pLocalImage) + reinterpret_cast<PIMAGE_DOS_HEADER>(pLocalImage)->e_lfanew);

	auto pSectionHeader = IMAGE_FIRST_SECTION(pNtHeaders);
	for (int i = 0; i < pNtHeaders->FileHeader.NumberOfSections; ++i, ++pSectionHeader)
	{
		pSectionHeader->PointerToRawData = pSectionHeader->VirtualAddress;
		pSectionHeader->SizeOfRawData = pSectionHeader->Misc.VirtualSize;
	}

	return 1;
}
