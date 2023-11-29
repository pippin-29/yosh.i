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
 
 # 1.05
 - made headway towards completion of run_complexcmd().
 - heredoc (<<) is functional (as redirection, but not as a parameter).
 - corrected expander when appending env vars.
 - expander.c now fits norm style guide.
 - signals now exit blocking functions, but dont exit shell.

 # 1.06
 - redirections seem to mostly work, i.e "cat < in > out" , "cat < in >> out", "cat in > out" (still more to test).
 - pipes are on their way
 - list of tokens is now being interpreted one command block at a time, whilst redirections are completed ahead of execution time.

 # 1.07
 - redirections work to the left and right of command now.
 - norminette styling applied
 - pipes now do nothing
 - ';' & '\' can no longer be interpreted, and yosh now presents an error.
 - looking like the final build for now, with pipes being elusive, and the need to move on, hopefully this project is a pass.

 # 1.07+
 - single pipes have been introduced.

 # 1.07+1 (Post Evaluation)
 - single and double quotes surrounding executable code is no longer executed.
	as was present in an earlier version
 - Headway has been made creating functions that update a copy of environ,
	as opposed to directly updating **environ.