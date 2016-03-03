set nocp ai si nu bs=2 so=3 mouse=a
set ts=4 sts=4 sw=4 hls showmatch
set noswapfile wildmenu wildmode=list:longest
syntax on | colorscheme evening

function! MyExecute(cmd)
let tmpnam=tempname()
    let tmpnam=tempname()
    let cmdstr=expand(a:cmd)
    exec "!".a:cmd." 2>&1| tee ".tmpnam
    if bufexists("ResultWindow") && bufwinnr("ResultWindow") > 0
        exe bufwinnr("ResultWindow")."wincmd w"
        set ma noro
    else
        bo 1split
        enew
        setlocal bt=nofile
        file ResultWindow
    endif
    exec "0"
    exec "normal dG"
    exec "r ".tmpnam
    exec "silent !rm ".tmpnam
    redraw!
endfunction

command! -nargs=1 Res call MyExecute(<f-args>) 

map <F5> <ESC>:w<CR>:!g++ -g -Wall --std=c++0x -O2 %:r.cpp -o %:r && %:r < %:r.in<CR>

map <C-B> <ESC>:w<CR>:!cp %:r.java Main.java && javac Main.java && java Main < %:r.in<CR>	

map <C-tab> :tabnext<CR>
map <C-S-tab> :tabprev<CR>

cd C:\Users\Minsu\Documents\Competitive-Programming
