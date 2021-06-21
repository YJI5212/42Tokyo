# minitalk

以下の2つのプログラムを作成する課題です。
- server  
  clientから送信されるbit列を受信し、文字列を復元・表示する。  
- client  
  serverをpidで指定し、文字列をbit列に変換しSIGUSR1,SIGUSR2をスイッチとして送信する。  
  
文字列を一文字ずつに分割し、さらに1文字32bitを1bitずつ送信することでUNICODE文字にも対応しています。  
