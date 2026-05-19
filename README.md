Данный репозиторий оммаж работе Вовы - https://github.com/VladimirAllmight/NMSTU_CGI_CPP
Мною были внесенны актуальные правки. Инструкцией по настройке пользуйтесь в его репозитории, здесь будет описанно только то что было изменено.

У Калитаева было требование, чтобы доступ к сайту был по адресу: http://localhost/lab4/ 
Для этого папочка cgi-bin была переименована в lab4, и в конфиге ./xampp/apache/conf/httpd.conf добавить это
  
  ScriptAlias /lab4/ "C:/xampp/lab4/"
  <Directory "C:/xampp/lab4">
      Options +ExecCGI
      AddHandler cgi-script .cgi .exe
      Require all granted
      AllowOverride None
  </Directory>
