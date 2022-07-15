import re

dict_except = ['вглубляться', 'ослаблять', 'ассамбляж', 'потреблять', 'расслабляться',\
               'блямба', 'блязик', 'дубляж', 'гребля', 'сабля']
dict_en = ['fuck', 'bitch', 'dick', 'pussy', 'admin', 'moder']
dict_ru = ['бля', 'сука', 'хуй', 'пизд', 'ебать', 'выеб', 'ебал', 'мудак', 'мудила',\
           'мудень', 'влагалище', 'вагина', 'хуе', 'пидр', 'пидор', 'пидaр']
dict_bk = {'q':'ку', 'w':'в', 'e':'е', 'r':'р', 't':'т', 'y':'й', 'u':'у', 'i':'и',
           'o':'о', 'p':'п', 'a':'а', 's':'с', 'd':'д', 'f':'ф', 'g':'г',
           'h':'х', 'j':'ж', 'k':'к', 'l':'л', 'z':'з', 'x':'х', 'c':'с', 'v':'в',
           'b':'б', 'n':'н', 'm':'м'}
while(True):
     inp = input('Попробуйте ввести мат: ').lower().replace('ё','е')
     nick = inp

     for n in range(0,len(inp)):
          if inp[n] in dict_bk:
               inp = inp.replace(inp[n],dict_bk[inp[n]])
     for n in range(0,len(dict_except)):
          if dict_except[n] in inp:
               inp = inp.replace(dict_except[n],'')
     inp = re.sub(r"[^а-яА-Я]",'',inp)
     print(inp)
     filthy = 0
     for n in range(0,len(dict_en)):
          if dict_en[n] in inp:
               filthy = 1       
     for n in range(0,len(dict_ru)):
          if dict_ru[n] in inp:
               filthy = 1       
     if (filthy == 1):
         print("Мат найден\n")
     else:
         print("Мата нет\n")

         
