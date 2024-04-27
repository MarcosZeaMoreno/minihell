# 🔥'Mini-hell'🔥

Minishell is a 42 cursus preject, which is a lightweight shell implementation written in C language. It provides a minimalistic command-line interface with basic shell functionalities, like pipes and redirections.

## 📚Implementation📚

To understood the porject, is needed to know it's parts. It breaks down the process into 4 steps:

`expander`->`lexer`->`parser`->`executor`. This process may vary depend on the proyect.

### Expander

First, we need to see in the input if we can fill any variable `$`, if is possible, we store and then we fill it with the value of the enviromental variable, only if there's a value, if not, we replaced with a `NULL` character. Then we return to lexer a copy of the input with the variables expanded.

### Lexer

This process is also called tokenizer, which takes an input (string) and reads word by word, using as delimitator the spaces before and after the words. If the word readed is not a word, we specify if it's a redirect, and finally setting the order of the tokens. Then we store in this struct, which is inside of a linked list:

```
typedef struct s_tkn
{
	enum
	{
		TKN_PIPE,
		TKN_REDIR_IN,
		TKN_REDIR_OUT,
		TKN_REDIR_APPEND,
		TKN_REDIR_HERE_DOC,
		TKN_WORD,
		TKN_STRING,
		TKN_ERROR
	} e_type;
	char				*value;
	int					order;
}						t_tkn;
```

### Parser

The job of this part turning tokens list into a command list like this:

```
typedef struct s_cmd
{
	char				**args;
	int					flag_redir;
	int					fd[2];
	t_redirect			*redir;
	int					redir_count[2];
	int					save;
	struct s_cmd		*next;
}						t_cmd;
```

The t_cmd struct represents a linked list where each node represents a command line. This linked list is used to store the commands that are separated by pipes in the input. An example is for this line `echo "Hello World!" | cat -e`, we have two list of commands, first `echo "Hello World!"` and then `cat -e`. We did it on a loop while there`s not more arguments or pipes or something.

 - args 			is a double char that contains the tokens type word
 - flag_redir		1 if there's a redir and 0 if not
 - fd[2]			is used to store the values of the file descriptor that we changed on the execution part
 - *redir			is a list that contains a string with the redir (example: "`<`") and the file name next to the redir
 - redir_count[2]	in redir_count[0] counts the inputs redirs and in redir_count[1] the outputs redirs
  - save			used to save the initial fd

### Executor

A pipeline is a sequence of commands separated by pipe characters `|`, where the output of each command is passed as the input to the next command.

We execute in a loop until there's not more commands, and we do this process:

 - Make a fork
 - Search redirs, execute it selfs in a loop until there's no more redirs, and change the fd
 - If there's a buildin execute outside the fork and change fd if not, execute the command in execve

When all commands are executed, if there are no outputs at the end, we send the custom outputs of the file descriptors to the standard output.

## 🎉Features🎉

### Basics:

- History of previous entered commands
- Search and launch the right executable (based on the PATH variable, using a relative or an absolute path)
- Environment variables ($ followed by a sequence of characters) expand to their values
- Wildcards * in the current working directory
- ctrl-C, ctrl-D and ctrl-\ behave like in bash
- `’` (single quotes - prevent from interpreting meta-characters in quoted sequence)
- `"` (double quotes - prevent from interpreting meta-characters in quoted sequence except for $)
- `$?` expands to the last exit status
- `|` connect cmds or groups with pipes; output of a cmd is connected to the input of the next cmd via a pipe
- `&&` and `||` with parenthesis for priorities

### Builtins:

- `echo` with option -n
- `cd` (relative or absolute path, and without arg for HOME)
- `pwd` without options
- `export` without arguments, it prints enviromental variables
- `unset` without options
- `env` without options
- `exit` with exit status

### Redirections:

- `>` for redirect output
- `>>` for append output
- `<` for redirect input
- `<<` for Heredoc

## 🛠️Dependencies🛠️

### Install readline on 42 Macs

Install Brew, *ONLY* if it is not already installed:

	rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

Install Readline library:

	brew install readline
	brew link --force readline
	echo 'export C_INCLUDE_PATH="$HOME/.brew/include:$C_INCLUDE_PATH"' >> ~/.zshrc
	echo 'export LIBRARY_PATH="$HOME/.brew/lib:$LIBRARY_PATH"' >> ~/.zshrc
	source ~/.zshrc
## 💻Usage💻

### Requirements:

- GCC / CLANG Compiler
- GNU Make
- GNU Readline library

### Steps:

To use 'Minihell', you need to clone the repository

	git clone https://github.com/MarcosZeaMoreno/minihell Minihell
	
Enter the folder and execute command `make`

	cd Minihell && make

And finally open the program

	./minishell

And you did it! Now use it however you want.
Try commands like `echo Hello 42Malaga!`, `export` or `clear`.

## Credit
This two-person project was created with my partner [vktasonov](https://github.com/vkatasonov).

I was responsible for the structure, built-in functions, execution, redirection, and piping of the project.

Vkatasonov was responsible for the parsing, error checking, and descriptions of the functions.
