set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

Plugin 'scrooloose/nerdtree'
Plugin 'valloric/youcompleteme'
Plugin 'scrooloose/nerdcommenter'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'vim-airline/vim-airline'
" Plugin 'vim-airline/vim-airline-themes'
Plugin 'morhetz/gruvbox'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" leader mapping
nnoremap <SPACE> <Nop>
let mapleader=" "

" editor settings
syntax on
set number 
set tabstop=4
set mouse=a
set ruler
set autoindent
set smarttab
set background=dark
set smartcase
set timeoutlen=1000
set ttimeoutlen=5
set backspace=indent,eol,start
set clipboard=unnamedplus
set shiftwidth=4
set cursorline

" key bindings
execute "set <A-k>=\ek"
execute "set <A-j>=\ej"
nmap <leader>y ggvGy
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>
nnoremap <A-j> :m .+1<CR>==
nnoremap <A-k> :m .-2<CR>==
inoremap <A-j> <Esc>:m .+1<CR>==gi
inoremap <A-k> <Esc>:m .-2<CR>==gi
vnoremap <A-j> :m '>+1<CR>gv=gv
vnoremap <A-k> :m '<-2<CR>gv=gv
imap <C-H> <C-W>

" templates
autocmd BufNewFile *.cpp 0r ~/.templates/cpp-template.cpp
autocmd BufNewFile *.java 0r ~/.templates/java-template.java

" compilation and build key bindings
autocmd filetype cpp nnoremap <F5> :<C-U>!g++ -O2 -DLOCAL -std=c++17 -Wshadow -Wall -Wextra -Wno-unused-result -static %:r.cpp<CR>
autocmd filetype cpp nnoremap <F6> :<C-U>!g++ -std=c++17 -Wshadow -Wall -o -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG %:r.cpp -o %:r<CR>
autocmd filetype cpp nnoremap <F9> :<C-U>!./a.out<CR>
autocmd filetype python nnoremap <F5> :w <bar> !python3 % <CR>
autocmd filetype java nnoremap <F5> :<C-U>!javac %:r.java<CR>
autocmd filetype java nnoremap <F9> :exec '!java Main'<cr>
autocmd filetype sh nnoremap <F9> :<C-U>!bash %:r.sh<CR>
autocmd filetype javascript nnoremap <F9> :<C-U>!node %:r.js<CR>

" nerdtree settings
nnoremap <C-n> :NERDTreeToggle<CR>

" youcompleteme settings
" let g:ycm_show_diagnostics_ui = 0
set completeopt-=preview
nnoremap <leader>gl :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>gf :YcmCompleter GoToDefinition<CR>
nnoremap <leader>gg :YcmCompleter GoToDefinitionElseDeclaration<CR>

" airline settings
" let g:airline_theme = 'minimalist'
let g:airline#extensions#tabline#enabled = 1
let g:airline_powerline_fonts = 1

" gruvbox settings
colorscheme gruvbox
