## yosh.i
A mini shell. 42.

## Installation

This program is currently being developed on macOS Catalina. (If you happen to be using this, it might work).
It works on M1 if you install a brew version of readline. The makefile will handle the rest.

There is a version that is available for testing on linux. My primary linux installation
is a debian base distro called PeppermintOS.

Type `` make `` in latest version directory (1.11). (This will also remake the library archive, and clean the object files away.)

This will create a directory in `` $HOME/bin ``

Run `` ./yosh.i `` within latest version directory.

Alternatively Append `` .bashrc `` or `` .zshrc `` file with `` export PATH=$PATH:$HOME/bin ``

Run from shell with `` yosh.i `` command.

Running the program will also create 1-3 files in user directory.
These are `` .yosh_history `` , `` .to-pipe `` & `` .temporary_heredoc ``

The two latter files are deleted upon typing the `` exit `` command.

Most terminals can also be pointed to an executable of choice, for immediate startup of shell upon window creation.

## Have a look :)

This is a screenshot of yosh.i v1_04 (on M1 mac, running in 'terminal' terminal emulator.)
![yosh.i M1 Terminal](https://github.com/pippin-29/yosh.i/blob/main/Screenshot2.png?raw=true)

# Current Features:
 - quote handling
 - file redirection. (First In or Out takes precedence)
	-  '<', '>', '|', '?' , '*' excluded from filenames
 - handles a single pipe. (pipe takes precedence over redirections)
 - command history (keys up/down) (saves & loads upon entry/exit)
 - directory autocomplete (using tab)
 - Enviroment variable expansion
 - Simple command execution i.e.    `` ls -la `` ``./a.out`` ``/bin/ls -la``
 - prompt ``🏠uname@hname :: yosh.i_1_03 [exitstatus] 💀>`` with colours.
 - builtin functions similar to bash
	-  export
	-  unset
	-  echo (with -n option)
	-  cd (with absolute or relative path, or no parameters, '~' unsupported)
	-  pwd
	-  env
	-  exit
 - signal handling
	-  ctrl-c (continues to next prompt, exits child process)
	-  ctrl-d (exit process)
	-  ctrl-\ (returns cursor to beginning, exits child process)


