# AGENTS.md

Edit AGENTS.md and README.md only when explicitly requested.

Freely manage PLAN.md, NOTES.md, and ARCHITECTURE.md for your own work. Keep them gitignored and never commit them.

## Language

- ISO/IEC 14882:2024 (C++23)
- C++ library: GNU libstdc++ 16.2
- C library: GNU C Library 2.44

## Platform

- Operating system: GNU/Linux, Linux kernel 7.0
- Triple: x86_64-pc-linux-gnu
- Architecture: x86-64
- ISA: x86-64-v1, x86-64-v2, x86-64-v3, native
- Endianness: little-endian
- ABI: x86-64 System V ABI

## Toolchain

- GNU Compiler Collection 16.2
- GNU Binutils 2.47
- GNU ld 2.47
- CMake 4.4
- Ninja 1.13
- CPack 4.4
- GNU Make 4.4
- Qt 6.12
- Qt Core 6.12
- Qt Qml 6.12
- Qt Quick 6.12
- Qt Quick Controls 6.12
- Qt Network 6.12
- CTest 4.4
- clang-format 23.1
- GNU gcov 16.2
- Valgrind 3.25
- GCC AddressSanitizer 16.2
- GCC UndefinedBehaviorSanitizer 16.2
- GCC ThreadSanitizer 16.2
- GCC LeakSanitizer 16.2
- Qt Test 6.12
- Qt Quick Test 6.12
- qmlformat 6.12
- qmllint 6.12

## Interfaces

GNU C Library feature test macro `_GNU_SOURCE` is enabled.

- IEEE Std 1003.1-2024
- X/Open System Interfaces Issue 8
- GNU C Library extensions 2.44
- Linux kernel interfaces 7.0
- GCC built-in functions 16.2
- GCC x86-64 intrinsics 16.2
- Qt C++ and QML interfaces 6.12

## EditorConfig

```ini
root = true

[*]
charset = utf-8
end_of_line = lf
indent_size = 4
indent_style = space
insert_final_newline = true
max_line_length = off
quote_type = single
trim_trailing_whitespace = true

[*.go]
indent_size = tab
indent_style = tab
tab_width = 8

[Makefile]
indent_size = tab
indent_style = tab
tab_width = 8
```

## Prettier

```js
import xml from '@prettier/plugin-xml';

export default Object.freeze({
    arrowParens: 'always',
    bracketSameLine: false,
    bracketSpacing: true,
    checkIgnorePragma: false,
    embeddedLanguageFormatting: 'auto',
    experimentalOperatorPosition: 'end',
    experimentalTernaries: false,
    htmlWhitespaceSensitivity: 'strict',
    insertPragma: false,
    jsxSingleQuote: false,
    objectWrap: 'preserve',
    plugins: Object.freeze([xml]),
    proseWrap: 'never',
    quoteProps: 'consistent',
    requirePragma: false,
    semi: true,
    singleAttributePerLine: true,
    singleQuote: true,
    trailingComma: 'all',
    vueIndentScriptAndStyle: true,
    xmlQuoteAttributes: 'double',
    xmlSelfClosingSpace: true,
    xmlSortAttributesByKey: false,
    xmlWhitespaceSensitivity: 'strict',
});
```

## Clang-Format

```yaml
---
BasedOnStyle: Microsoft
ColumnLimit: 0
NamespaceIndentation: All
InsertBraces: true
BreakBeforeBraces: Allman
SeparateDefinitionBlocks: Always
WrapNamespaceBodyWithEmptyLines: Always
InsertNewlineAtEOF: true
LineEnding: LF
...
```
