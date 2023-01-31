jQuery(document).ready(function () {
     
    jQuery('.send-form').click( function() {
    	var form = jQuery(this).closest('form');
    	
    	if ( form.valid() ) {
    		form.css('opacity','.5');
    		var actUrl = form.attr('action');

    		jQuery.ajax({
    			url: actUrl,
    			type: 'post',
    			dataType: 'html',
    			data: form.serialize(),
    			success: function(data) {
    				form.html(data);
    				form.css('opacity','1');
                    //form.find('.status').html('форма отправлена успешно');
                    //$('#myModal').modal('show') // для бутстрапа
    			},
    			error:	 function() {
    			     form.find('.status').html('серверная ошибка');
    			}
    		});
    	}
    });


});

const btnOpen = document.querySelector('.btn_reserve');
const menu = document.querySelector('.window_module');
const btnClose = document.querySelector('.btn_close');
btnOpen.onclick = function (){
    menu.style.display = 'block';
};

btnClose.onclick = function (){
    menu.style.display = 'none';
}

const meneBurgerBtn = document.querySelector('.menu_burger_btn');
const meneBurger = document.querySelector('.menu_list');
let showMenu = false;


meneBurgerBtn.onclick = function(){
	if (showMenu === false){
	meneBurger.style.display = 'block';
	meneBurger.style.position = 'fixed';
	meneBurger.style.top = '50px';
	meneBurger.style.background = '#3a4574';
	meneBurger.style.width = '100%';
	meneBurger.style.height = '250px';
	meneBurger.style.transform = 'translateY(0px)';
	const elementsMenu = document.querySelectorAll('.menu_list_element')
	for(let k of elementsMenu){
		k.style.marginTop = "25px";
	}
	showMenu = true;
}else
{
	meneBurger.style.transform = 'translateY(-500px)';
	meneBurger.style.display = 'block';
	showMenu = false;
}
}