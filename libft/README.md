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
                                               : s1とs2を最大sizeバイト分だけ比較しその差分を返す関数
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
  - `char *ft_strmapi(const char *str, char (*f)(unsigned int, char))`
                                               : 文字列strのi番目(0~len(str)-1)に対応する処理を関数fで行い返り値の配列をとる関数  
  - `int ft_strncmp(const char *s1, const char *s2, size_t size)`
                                               : 文字列s1と文字列s2を最大n文字分だけ比較しその差分を返す関数  
  - `char *ft_strnstr(const char *str, const char *target, int size)`
                                               : 文字列strの中に文字列targetが含まれるか否か最大size(実際にはtarget長を引いたsize - len(target))文字分だけ捜索する関数  
  - `char *ft_strrchr(const char *str, int c)` : 文字列strの中で初めて文字cが現れる位置を返す関数  
  - `char *ft_strtrim(const char *str, const char *set)`
                                               : 文字列strの中から文字列setに含まれない部分のみを抽出する関数  
  - `char *ft_substr(const char *str, unsinged int start, size_t len)`
                                               : 文字列strについてstart番目から長さlen分だけ複製する関数  
  - `int ft_tolower(int c)`                    : 文字cを大文字のアルファベットから小文字に変換する関数  
  - `int ft_toupper(int c)`                    : 文字cを小文字のアルファベットから大文字に変換する関数  
  - ### 以下、bonusパート
  - `typedef struct s_list  
  {  
    void          *content;  
    struct s_list *next;  
  } t_list;`                                   : bonusパートではこのような線形リストについての関数を作成する  
  - `void ft_lstadd_back(t_list **lst, t_list *new)`
                                               : 線形リストlstの最後尾に新規セルnewを追加する関数  
  - `void ft_lstadd_front(t_list **lst, t_list *new)`
                                               : 先頭に追加するバージョン  
  - `void ft_lstdelone(t_list **lst, void (*del)(*void))`
                                               : 線形リストlstの先頭要素を削除する関数  
  - `void ft_lstclear(t_list **lst, void (*del)(*void))`
                                               : 線形リストlstの要素全てを削除する関数  
  - `void ft_lstiter(t_list *lst, void *(*f)(void *))`
                                               : 線形リストlstの要素全てに関数fを作用させる関数  
  - `t_list *ft_lstlast(t_list *lst)`          : 線形リストlstの末尾のアドレスを返す関数  
  - `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`
                                               : 線形リストlstの各要素に関数fを作用させた新しい線形リストを返す関数  
  - `t_list *ft_lstnew(void *content)`         : 要素contentを持った長さ1の(線形)リストを新規作成する関数  
  - `int ft_lstsize(t_list *lst)`              : 線形リストlstの長さを返す関数  
