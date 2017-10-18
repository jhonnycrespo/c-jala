int main()
{
    // allocate 6 bytes in the stack and store "hello" in them.
    char stack[] = "hello";

    // allocate pointer in the stack and point it to a static, read-only buffer
    // containing "hello".
    const char* heap = "hello";

    // allocate 5 bytes (which is isn't enough to hold "hello" due to the \0 character) in the heap.
    char* heap_string_malloc = malloc(5);

    // reset heap_string_malloc to point to a static buffer; memory leak!!
    heap_string_malloc = "hello";
}