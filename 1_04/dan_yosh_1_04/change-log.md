## Changes

# 1.01
 - added skull in readline prompt. (setup.c)
 - expanded error handling in run_simplecmd(), including bad command (specified as error code 2: no file or directory) (run.c)
 - created function retrv_envv() which is designed to replace the getenv() function. (env.c) (builtin1.c)
 - assigned enviroment variable is retrieved by env_grab_value


# 1.02 - 1.04
 - added load_history
 - added save_history
 - applied norminette style guide conventions
 - replaced straggling variables with struct members of same name (cmd struct) to save lines for style guide.
 - enviroment variables now correctly expanded from input. (aside from ignoring expansion within single quotes.)
 - a large portion of code removed from v1.02, as fresh perspective might be the best way to achieve a stable platform.
 - prompt within shell is now assembled with norminette-happy function call to strjoin_e (libft). This will allow for further expansion (configuration files, etc.)
 - removed global variable g_estatus and decided on an encapsulation of the variable with cmd struct.
 - echo works with nothing to echo
 