set nocp ai si nu et bs=2 mouse=a
set ts=2 sts=2 sw=2 hls showmatch
set ruler rulerformat=%17.(%l:%c%)
set noswapfile autoread wildmenu wildmode=list:longest
syntax on

map <C-b> <ESC>:w<CR>:!g++ -g -Wall --std=c++0x -O2 %:r.cpp -o %:r && %:r < %:r.in > %:r.out<CR>
map <F6> <ESC>:w<CR>:!g++ -g -Wall --std=c++0x -O2 %:r.cpp -o %:r && %:r < %:r.in<CR>

map k gk
map j gj

map <C-h> <C-w>h
map <C-j> <C-w>j
map <C-k> <C-w>k
map <C-l> <C-w>l
map <C-a> <C-w>
map <C-q> "+p 

map <C-t> :tabnew<CR>

command -nargs=1 PS :tabnew <args>.cpp | vs <args>.in | sp <args>.out | vertical res 20
