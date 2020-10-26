time before cyberpunk2077

[RU]
отсчитывает время до 00:00 19.11.2020 по UTC.

оформление сделано по скриншотам записи трансляции CD Project Red. графическая составляющая основана на библиотеке SDL.
писал для себя, поэтому настройки в виде изменения файла "cfg.txt". в нем 4 строки.
1) в каком углу располагается таймер. 1==правый верхний; 2==правый нижний; 3==левый нижний; 4==левый верхний.
2) ширина виджета. принимает значение 60-1200 пикселей. если указано значение вне этого промежутка, принимает значение 400.
3) отступ от нижней границы, чтобы его не закрывала панель задач. по дефолту установлено 40 для мониторов 1920х1080 со стандартным оформлением виндовс 10.
4) сколько часов добавить к таймеру. пригодится, когда будет известно точное время запуска игры для каждого часового пояса

выключается таймер прогой closeTimer.exe ,как видите, она лежит рядом.

p.s.писал один вечер на коленке, прошу простить за отсутствие комментариев в коде и определенные косяки. потом исправлю
jameskirk865 



[EN]
time before cyberpunk2077

countdown to 00:00 11.19.2020 UTC

design based on screenshots from stream recording CD Project Red. graphic component based on SDL library for c++.

i write it for myself, so settings are in form of file changes "cfg.txt". it has 4 lines:
1) in which corner the timer is located. 1==up-right; 2==down-right; 3==down-left; 4==up-left.
2) widget width. in the value 60-1200 pixels. if a value is specified outside this interval, it takes the value 400.
3) indent from the lower border so that it is not covered by the taskbar. by default, 40 is set for 1920x1080 monitors with the standard Windows 10 design.
4) how many hours to add to the timer. it will be useful when you know the exact launch time of the game for each time zone.

the timer is turned off by the program closeTimer.exe as you can see, it is lying nearby.

p.s.sorry, my english is so-so
jameskirk865 
