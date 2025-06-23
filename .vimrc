set bg=dark
syntax on                      " Abilita l'evidenziazione della sintassi
set number                     " Mostra i numeri di riga
set relativenumber             " Numeri di riga relativi
set tabstop=2                  " Imposta la larghezza del tab a 2 spazi
set shiftwidth=2               " Imposta il numero di spazi per indentazione
set expandtab                  " Usa spazi invece di tab
set smartindent                " Indentazione intelligente
set autoindent                 " Mantiene l'indentazione
set nowrap                     " Evita il wrapping automatico
set clipboard=unnamedplus

set scrolloff=8
set mouse=a 

autocmd VimEnter * 
      \ if filereadable('input.txt') | tabedit input.txt | endif |
      \ execute 'tabfirst'

nnoremap <Tab> :tabprevious<CR>
nnoremap <S-Tab> :tabnext<CR>

inoremap {<CR> {<CR>}<Esc>O

autocmd FileType cpp noremap <F6> :w <bar> !clear && g++ -D MYDEBUG -std=c++17 -fsanitize=address -g -Og -Wall -Wextra %:t -o %:r && ./%:r < input.txt<CR>
autocmd FileType cpp noremap <F7> :w <bar> !clear && g++ -D MYDEBUG -std=c++17 -fsanitize=address -g -Og -Wall -Wextra %:t -o %:r && ./%:r <CR>

autocmd FileType cpp noremap <F8> :w <bar> !clear && g++ -D MYDEBUG -std=c++17 -O2 %:t -o %:r && ./%:r < input.txt<CR>
autocmd FileType cpp noremap <F9> :w <bar> !clear && g++ -D MYDEBUG -std=c++17 -O2 %:t -o %:r && ./%:r<CR>
autocmd FileType cpp noremap <F10> :w <bar> !clear && g++ -D MYDEBUG -std=c++17 -O2 %:t -o %:r && ./%:r < input.txt > output.txt & ; tail -f output.txt<CR>

let &t_SI = "\e[6 q"  " Modalità inserimento (linea verticale)
let &t_EI = "\e[2 q"  " Modalità normale (blocco)

set timeoutlen=1000 ttimeoutlen=0

inoremap <silent><expr> <CR> pumvisible() ? "\<C-y>" : "\<CR>"
