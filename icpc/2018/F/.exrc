if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <C-C> ;
noremap ; :
xmap gx <Plug>(open-word-under-cursor)
nmap gx <Plug>(open-word-under-cursor)
xnoremap <Plug>(open-word-under-cursor) <ScriptCmd>vim9.Open(getregion(getpos('v'), getpos('.'), { type: mode() })->join())
nnoremap <Plug>(open-word-under-cursor) <ScriptCmd>vim9.Open(GetWordUnderCursor())
imap  ;
let &cpo=s:cpo_save
unlet s:cpo_save
set autochdir
set autoindent
set autoread
set background=dark
set backupdir=~/.cache/vim/backup//
set directory=~/.cache/vim/swap//
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set makeprg=g++\ -Wall\ -Wconversion\ -Wshadow\ -Wfatal-errors\ -DLOCAL\ -g\ -std=c++20\ -fsanitize=undefined,address\ %:r.cpp
set ruler
set runtimepath=~/.vim,/usr/share/vim/vimfiles,/usr/share/vim/vim91,/usr/share/vim/vim91/pack/dist/opt/netrw,/usr/share/vim/vimfiles/after,~/.vim/after
set shellcmdflag=-ic
set shiftwidth=4
set suffixes=.bak,~,.o,.info,.swp,.aux,.bbl,.blg,.brf,.cb,.dvi,.idx,.ilg,.ind,.inx,.jpg,.log,.out,.png,.toc
set tabstop=4
set ttimeoutlen=100
set undodir=~/.cache/vim/undo//
" vim: set ft=vim :
