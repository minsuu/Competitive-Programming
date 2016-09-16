set nocp ai si nu et bs=2 mouse=a
set ts=4 sts=4 sw=4 hls showmatch
set ruler rulerformat=%17.(%l:%c%)
set noswapfile autoread wildmenu wildmode=list:longest
set autoindent smartindent cindent autoread
syntax on

map <C-j> <ESC>:w<CR>:!cp %:r.java Main.java<CR>:!javac Main.java && java Main < %:r.in > %:r.out<CR>
map <C-b> <ESC>:w<CR>:!g++ -g -Wall --std=c++0x -O2 %:r.cpp -o %:r.o && %:r.o < %:r.in > %:r.out<CR>
map <F6> <ESC>:w<CR>:!g++ -g -Wall --std=c++0x -O2 %:r.cpp -o %:r.o && %:r.o < %:r.in<CR>
nnoremap tc :tabclose<CR>

map k gk
map j gj

map <C-a> <C-w>
map <C-q> "+p

map <C-t> :tabnew<CR>

command W w

command -nargs=1 PS :tabnew <args>.cpp | if !filereadable('<args>.cpp') | read template.cpp | endif | silent execute '!touch <args>.out' | vs <args>.out | sp <args>.in | vertical res 20 
command -nargs=1 PJ :tabnew <args>.java | if !filereadable('<args>.cpp') | read template.cpp | endif | silent execute '!touch <args>.out' | vs <args>.out | sp <args>.in | vertical res 20 
