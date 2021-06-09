# libft
C言語の標準関数+αを自作する課題です。  
## 関数一覧
  - `int ft_atoi(char *str)`                   : 引数の文字列strをintに変換する関数  
  - `void ft_bzero(void *s, size_t n)`         : 引数の要素列sを長さnだけ0埋めする初期化関数  
  - `void *ft_calloc(size_t num, size_t size)` : num(要素数) x size(型のbyte数)の長さのメモリをmallocし、同時に0で初期化する関数  
  - `int ft_isalnum(int c)`                    : 引数の文字cがアルファベットまたは数字に該当するか判定する関数  
  - `int ft_isalpha(int c)`                    : 引数の文字cがアルファベットに該当するか判定する関数  
  - `int ft_isascii(int c)`                    : 引数の文字cがasciiコードに該当するか判定する関数  
  - `int ft_isdigit(int c)`                    : 引数の文字cが整数に該当するか判定する関数
  - `int ft_isprint(int c)`                    : 引数の文字cが表示文字に該当するか判定する関数
  - `char *ft_itoa(int n)`                     : 引数の整数nを文字列に変換する関数  
  - `void *memcpy(void *dst, const void *src, size_t n)`
                                               : srcからdstへnバイト分コピーする関数  
  - `void *ft_memccpy(void *dst, void *src, int c, size_t n)`
                                               : srcからdstへ文字cが見つかるまで最長nバイト分コピーする関数  
  - `void *memchr(const void *buf, int c, size_t n)`
                                               : bufに対し文字cを含むか否か最大nバイト分捜索する関数  
  - `int memcmp(const void *s1, const void *s2, size_t size)`
                                               : sizeバイト分だけs1とs2を比較しその差分を返す関数
  - `void *memmove(void *dst, const void *src, size_t size)`
                                               : srcからdstへsizeバイト分コピーする関数(メモリ領域が重複する場合もコピーは成功する)  
  - `void *memset(void *buf, int c, size_t size)`
                                               : bufをsizeバイト分だけ文字cで埋める関数  
  - `void ft_putchar_fd(char c, int fd)`       : 文字cを指定されるfdに出力する関数  
  - `void ft_putstr_fd(char *str, int fd)`     : 文字列strを指定されるfdに出力する関数  
  - `void ft_putendl_fd(char *str, int fd)`    : 文字列strの末尾に改行を施し指定されるfdに出力する関数  
  - `void ft_putnbr_fd(int n, int fd)`         : 数字nを指定されるfdに出力する関数  
  - `char **ft_split(const char **str, char c)`
                                               : 文字列strを文字cで分割し、各要素の文字列を配列として返す関数  
  - `char *ft_strchr(const char *str, int c)`  : 文字列strの中に文字cが含まれるか否か判定する関数  
  - `char *ft_strdup(const char *str)`         : 文字列strを新たなメモリ領域に複製する関数  
  - `char *ft_strjoin(const char *s1, const char *s2)`
                                               : 文字列s1の末尾に文字列s2を結合する関数  
  - `size_t ft_strlen(const char *str)`        : 文字列strの長さを返す関数  
  - `size_t ft_strlcpy(char *dst, char *src, size_t size)`
                                               : srcからdstへ最大sizeバイト分コピーする関数  
  - `size_t ft_strlcat(char *dst, const char *src, size_t size)`
                                               : srcをdst末尾に結合し最大でsizeバイトとする関数  
  - `char *ft_strmapi(const char *s, char (*f)(unsigned int, char))`
                                               : 
