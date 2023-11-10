## yosh.i
A mini shell. 42.

# Current Features:

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
