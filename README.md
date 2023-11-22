## yosh.i
A mini shell. 42.

## Installation

This program is currently being developed on macOS Catalina. (If you happen to be using this, it might work).
It works on M1 (IF!) you install a brew version of readline. The makefile will handle the rest.
And it is quite buggy in terms of the allocated buffer on stdout. (On M1).

I have no guarantee that this works on linux in any way shape or form...

Type `` make run `` in latest version directory.

## Have a look :)

This is a screenshot of yosh.i v1_04 (on M1 mac, running in 'terminal' terminal emulator.)
![yosh.i M1 Terminal](https://github.com/pippin-29/yosh.i/blob/main/Screenshot2.png?raw=true)

# Current Features:

quote handling

file redirection (in, out, append and heredoc)

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

pipes

Under consideration:
  -  Configuration file for prompt customisation (colours, special characters, etc.).

