# MiniBank

## Funkcjonalności

- Rejestracja klientów (imię, nazwisko, PESEL)
- Tworzenie kont bankowych (główne i oszczędnościowe)
- Wpłaty i wypłaty środków
- Przeglądanie salda i informacji o koncie

## Struktura projektu

```
MiniBank/
├── Account.cpp / Account.h       
├── Bank.cpp / Bank.h             
├── Client.cpp / Client.h         
├── MiniBank.cpp                  
├── MiniBankGUI/                  
│   ├── MiniBankGUI.cpp/.h        
│   ├── MiniBankGUI.ui            
│   └── main.cpp                
└── MiniBankUnitTests/           
```

## Technologie

- **C++17**
- **Qt 6.11** — interfejs graficzny
- **Visual Studio 2022** — środowisko deweloperskie
- **Google Test** — testy jednostkowe
- **Git** — kontrola wersji

## Uruchomienie

1. Otwórz `MiniBank.sln` w Visual Studio 2022
2. Ustaw projekt `MiniBankGUI` jako projekt startowy
3. Skompiluj i uruchom (F5)

## Testy jednostkowe

Testy znajdują się w projekcie `MiniBankUnitTests` i pokrywają klasy `Account`, `Bank` oraz `Client`.

Aby uruchomić testy, ustaw `MiniBankUnitTests` jako projekt startowy i uruchom.

## Historia Git
```
nothing added to commit but untracked files present (use "git add" to track)
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git add .
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git commit -m "Add account class"
[master be23f88] Add account class
 2 files changed, 71 insertions(+)
 create mode 100644 Account.cpp
 create mode 100644 Account.h
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 16 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 1.14 KiB | 1.14 MiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/ZuziakF/MiniBank.git
   1552c2c..be23f88  master -> master
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   Account.cpp
        modified:   Account.h

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        Bank.cpp
        Bank.h
        MiniBank.cpp

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git add .
PS C:\Users\filip\OneDrive\Desktop\1\Praca\MiniBank> git commit -m "Add Bank class"
[master 144b511] Add Bank class
 5 files changed, 47 insertions(+), 14 deletions(-)
 create mode 100644 Bank.cpp
 create mode 100644 Bank.h
 create mode 100644 MiniBank.cpp
```
## Użyte komendy Git

```bash
git status                        
git add .                       
git commit -m "opis"              
git push                         
git push origin master --force    
git branch -a                   
git checkout nazwa-brancha       
git merge nazwa-brancha          
git pull origin master           
git log --oneline                 
git reset --hard hash-commita     
git rebase ....                    
```
