## yosh.i
A mini shell. 42.

## Installation

This program is currently being developed on macOS Catalina. (If you happen to be using this, it might work).
It works on M1 (IF!) you install a brew version of readline. The makefile will handle the rest.


I have no guarantee that this works on linux in any way shape or form...
I now have some guarantee this works on linux. (Since the evaluation of 1.07 at school)

Type `` make `` in latest version directory.

This will create a directory in `` $HOME/bin ``

Append `` .bashrc `` or `` .zshrc `` file with `` export PATH=$PATH:$HOME/bin ``

Run from shell with `` yosh.i `` command.

Running the program will also create 1-3 files in user directory.
These are `` .yosh_history `` , `` .to-pipe `` & `` .temporary_heredoc ``

The two latter files are deleted upon typing the `` exit `` command.

Most terminals can also be pointed to an executable of choice, for immediate startup of shell upon window creation.

## Have a look :)

This is a screenshot of yosh.i v1_04 (on M1 mac, running in 'terminal' terminal emulator.)
![yosh.i M1 Terminal](https://github.com/pippin-29/yosh.i/blob/main/Screenshot2.png?raw=true)

# Current Features:

quote handling

file redirection

handles a single pipe.

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

