function allocateStringMemory(value, wasmModule){
    const lengthBytes = (wasmModule.lengthBytesUTF8(value) + 1);
    const stringPtr = wasmModule._malloc(lengthBytes);

    wasmModule.stringToUTF8(value, stringPtr, lengthBytes);
    return {memoryPointer: stringPtr, freeMemory: () => {
        // TODO: free memory
        }};

}