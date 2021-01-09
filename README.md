
### [RU][1] Описание проекта на русском
[1]: https://github.com/udraugr/ft_ls/tree/master#ft_ls---%D1%81%D0%BE%D0%B1%D1%81%D1%82%D0%B2%D0%B5%D0%BD%D0%BD%D0%B0%D1%8F-%D1%80%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-ls "RU"
### [EN][2] Description of the project in English
[2]: https://github.com/udraugr/ft_ls#ft_ls---own-implementation-of-ls "EN"

# FT_LS - собственная реализация ls
ls - это утилита, отображающее содержимое каталога.
Проект был выполнен в Школе Программирования 21 (филиал французкой школы "Ecole 42").

# Сборка проекта:
Для того, чтобы собрать проект, необходимо зайти в корневой каталог проекта и в терминале прописать команду **make**

# Запус проекта:
**./ft_ls [-Ralrt] [file ...]**

# Функционал:
Показавыет содержимое каталога, реализованы следующие флаги:
* -R - Рекурсивно перечислияет встреченные подкаталоги
* -a - Включяет записи каталога, имена которых начинаются с точки (.)
* -r - Переворачивает порядок сортировки, чтобы сначала получить обратный лексикографический порядок или самые старые записи
* -t - Сортирует по времени последнего изменения (последнее изменение - первое), перед сортировкой операндов по лексикографическому порядку.
* -l - Список в длинном формате. Если выводится в терминал, то общая сумма по всем размерам файлов выводится в строке перед длинным списком.
     При установке опции -l для каждого файла отображается следующая информация: права файла, количество ссылок,
     имя владельца, название группы, количество байтов в файле,
     сокращенный месяц, последний раз изменен файл с указанием дня недели, последний раз изменен файл с указанием часа,
     последний раз изменен файл с указанием минуты, а также путь.
     Кроме того, для каждой директории, содержимое которой отображается, общее количество блоков размером 512 байт,
     используемых файлами в этой директории, отображается самой строкой, непосредственно перед информацией для файлов в этой директории.
     Если файл или каталог имеет расширенные атрибуты, в поле разрешения, распечатываемом параметром -l, добавляется символ '@'.
     В противном случае, если файл или директория имеет расширенную информацию о безопасности (например, список контроля доступа),
     за полем прав доступа, распечатанным с помощью опции -l, следует символ "+". Если время модификации файла больше 6 месяцев в прошлом или будущем,
     то вместо полей часов и минут отображается год последней модификации.
     Если имя владельца или имя группы не является известным пользователем или именем группы,
     то отображаются числовые идентификаторы.
     Если файл является файлом со специальным символом или блочным специальным файлом,
     то в поле размера отображаются номера основных и второстепенных устройств для файла.
     Если файл является символической ссылкой, то перед именем файла, с которым связана ссылка, ставится ``->''.
     Режим работы с файлом, распечатанным под опцией -l, состоит из типа записи, прав владельца и групповых прав.
     Символ типа записи описывает тип файла следующим образом:
     
           b Блокировать специальный файл.
           c Символьный специальный файл.
           d Каталог.
           l Символическая ссылка.
           s Ссылка на сокет.
           p FIFO.
           - Обычный файл.
     Следующие три поля состоят из трех символов: разрешения владельца, групповые разрешения и другие разрешения.  Каждое поле имеет три позиции символов:
     
           1.   Если r, то файл читается; если -, то он не читается.
           2.   Если w, то файл доступен для записи; если -, то он не доступен для записи.
           3.   Применяется первое из следующего:
           
              S Если в правах владельца файл не является исполняемым и установлен режим set-user-ID (Идентификатор пользователя).
                Если в правах собственности файл не является исполняемым, то устанавливается режим set-group-ID (Идентификация группы).
              s Если в правах собственности файл является исполняемым, устанавливается режим set-user-ID.
                Если в групповых правах доступа установлен режим "Исполняемый файл" и "Идентификация группы", то файл является исполняемым,
                а для него установлен режим "Идентификация группы".
              x Файл является исполняемым или имеет возможность поиска по каталогу.
              - Файл не является ни читаемым, ни записываемым, ни исполняемым, ни режимом set-user-ID, ни режимом set-group-ID, ни липким.
              
              Следующие два применяются только к третьему символу в последней группе (другие разрешения):
              
              T Липкий бит установлен (режим 1000), но не выполняется и не выполняются права на поиск.
              t Липкий бит установлен (режим 1000), но не может быть использован для выполнения или поиска.

### Примечание:
Этот проект полностью написан в школе программирования 21, и принадлежит ей.


# FT_LS - my own implementation of ls
ls is a utility which displays the contents of the directory.
The project was done at Programming School 21 (a branch of the French school "Ecole 42").

# Build the project:
In order to build the project, you need to go to the root directory of the project and in the terminal type the command **make**

# Run the project:
**./ft_ls [-Ralrt] [file ...]**

# Functionality:
Shows the contents of the directory, the following flags are implemented:
* -R - Recursively lists the encountered subdirectories
* -a - Includes directory entries whose names begin with a dot (.)
* -r - Reverses the sort order, to get the reverse lexicographic order or the oldest entries first
* -t - Sorts by time of last change (last change is first), before sorting operands in lexicographic order.
* -l - List in long format.  If output to the terminal, the total of all file sizes is output on the line before the long list.
     If option -l is set, the following information is displayed for each file: file rights, number of references,
     owner name, group name, and the number of bytes in the file,
     abbreviated month, last modified file specifying the day of the week, last modified file specifying the hour,
     last modified file by minute, and path.
     In addition, for each directory whose contents are displayed, the total number of 512 byte blocks
     used by files in that directory is displayed on the line itself, just before the information for files in that directory.
     If the file or directory has extended attributes, the '@' character is added to the permission field printed by the -l parameter.
     Otherwise, if the file or directory has extended security information (such as an access control list),
     The permissions field printed with the -l option is followed by a '+' character.
     If the file modification time is more than 6 months in the past or future,
     the year of the last modification is displayed instead of the hour and minute fields.
     If the owner name or group name is not a known user or group name,
     then numeric identifiers are displayed.
     If the file is a special character file or block special file,
     the size field displays the primary and secondary device numbers for the file.
     If the file is a symbolic link, ``->'' is placed before the name of the file to which the link is linked.
     The mode of the file printed under the -l option consists of record type, owner rights and group rights.
     The write type character describes the file type as follows:
     
           b Lock special file.
           c Symbol special file.
           d Directory.
           l Symbolic link.
           s Socket reference.
           p FIFO.
           - A normal file.
     The following three fields consist of three characters: owner permissions, group permissions, and other permissions.
     Each field has three character positions:
     
           1.   If r, the file is readable; if -, it is unreadable.
           2.   If w, the file is writable; if -, it is not writable.
           3.   The first of the following applies:
           
              S If the file is not executable in the ownership rights and the set-user-ID mode is set.
                If the file is not executable in the ownership, the set-group-ID mode is set.
              s If the file is executable in the permissions, the set-user-ID mode is set.
                If in the group permissions the mode "Executable file" and "Group-ID" are set, the file is executable,
                and it is set to "Group ID" mode.
              x The file is executable or searchable by directory.
              - The file is neither readable, writeable, executable, set-user-ID mode, set-group-ID mode, nor sticky.
              
              The following two apply only to the third character in the last group (other permissions):
              
              T Sticky bit is set (mode 1000), but is not executed or search permissions are not executed.
              t The sticky bit is set (mode 1000) but cannot be executed or searched.

### Note:
This project is done at programming School 21, and belongs to it.
