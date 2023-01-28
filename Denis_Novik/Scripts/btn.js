let buttonmenu = document.querySelector('.m_btn');
let open_menu = false;
let listheade = document.querySelector('.header_list');
let link_button = document.querySelectorAll('.header_link');


buttonmenu.onclick = function(){
    if (open_menu == false){
      listheade.classList.add('open_menu');
      open_menu=true; 
    }
    else{
        listheade.classList.remove('open_menu'); 
        open_menu=false;
    }
}

for(let link of link_button){
    link.onclick = function(){
        listheade.classList.remove('open_menu');  
        open_menu = false;
        link.classList.add('class_bold')
    }  
}