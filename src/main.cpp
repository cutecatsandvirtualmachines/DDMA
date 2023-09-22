#include "ddma.h"
#include <ntifs.h>

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObj, PUNICODE_STRING pRegistryPath) {
    UNREFERENCED_PARAMETER(pRegistryPath);

    PVOID pBase = pDriverObj;

    PVOID pBuffer = ExAllocatePool(NonPagedPool, PAGE_SIZE);
    if (!pBuffer)
        return STATUS_INSUFFICIENT_RESOURCES;
    RtlZeroMemory(pBuffer, PAGE_SIZE);

    DdmaProvider dma;
    dma.DiskCopyPage(pBuffer, pBase);

    PVOID pBufferPost = ExAllocatePool(NonPagedPool, PAGE_SIZE);
    if (!pBufferPost)
        return STATUS_INSUFFICIENT_RESOURCES;
    RtlZeroMemory(pBufferPost, PAGE_SIZE);
    dma.DiskCopyPage(pBufferPost, pBase);

    DbgPrintEx(0, 0, "[TEST] MZ check: %s\n", (char*)pBase);
    DbgPrintEx(0, 0, "[TEST] MZ check: %s\n", (char*)pBuffer);
    DbgPrintEx(0, 0, "[TEST] MZ check: %s\n", (char*)pBufferPost);

	return STATUS_SUCCESS;
}