# CGI Lab 4

Данный репозиторий - оммаж работе [Вовы](https://github.com/VladimirAllmight/NMSTU_CGI_CPP). Инструкцией по настройке пользуйтесь в его репозитории, здесь будет описанно только то что было изменено.

Я внёс актуальные правки и доработки под требования преподавателя.

---

## Единственное серьезное изменение
У Калитаева появилось требование, чтобы доступ был по адресу -  `http://localhost/lab4/`

- Переименована папка `cgi-bin` → `lab4` для соответствия требованиям
- Настроен доступ по адресу: `http://localhost/lab4/`

---

## Настройка Apache (httpd.conf)

Добавьте следующие строки в конфигурационный файл `./xampp/apache/conf/httpd.conf`:

```apache
ScriptAlias /lab4/ "C:/xampp/lab4/"

<Directory "C:/xampp/lab4">
    Options +ExecCGI
    AddHandler cgi-script .cgi .exe
    Require all granted
    AllowOverride None
</Directory>
