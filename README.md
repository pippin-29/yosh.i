## yosh.i
A mini shell. 42.

## Installation

This program is currently being developed on macOS Catalina. (If you happen to be using this, it might work).
It works on M1 (IF!) you install a brew version of readline. The makefile will handle the rest.
And it is quite buggy in terms of the allocated buffer on stdout. (On M1).

I have no guarantee that this works on linux in any way shape or form...

Type `` make run `` in latest version directory.

# Current Features:

command history (keys up/down)

directory autocomplete (using tab)

Enviroment variable Expansion

Simple command execution i.e.    `` ls -la `` ``./a.out`` ``/bin/ls -la``

builtin functions similar to bash
  -  export
  -  unset
  -  echo
  -  cd
  -  pwd
  -  env

signal handling for ctrl-c

prompt ``🏠uname@hname :: yosh.i_1_03 [exitstatus] 💀>`` with colours.

# Future Features

Complex commands i.e. `` ls -la | wc -l > file.out `` ``< file.in wc -l | cat -e ``

Quote handling.

Redirection in append mode. ( >> file.out )

Heredoc ( << EOF )

Under consideration:
  -  Configuration file for prompt customisation (colours, special characters, etc.).

# 1_04

Primarily concerns a rejig of the current codebase, structs have been expanded where they can, and global variables have been removed if possible.

Norminette styling has been mostly applied, with the exception of one function with too many lines.

Also history function was extended, as now there is a save and load function at program exit/entry.
