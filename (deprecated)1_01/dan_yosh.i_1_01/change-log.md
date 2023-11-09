# Changes

 - added skull in readline prompt. (setup.c)
 - expanded error handling in run_simplecmd(), including bad command (specified as error code 2: no file or directory) (run.c)
 - created function retrv_envv() which is designed to replace the getenv() function. (env.c) (builtin1.c)
    - assigned enviroment variable is retrieved by env_grab_value