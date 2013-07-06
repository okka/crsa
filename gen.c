#include <gtk/gtk.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void calcul(GtkButton *button, GtkWidget *gen);

int main(int argc, char *argv[])
{
    GtkWidget *window;  GtkWidget *gen; 
    GtkWidget *vbox;
    GtkWidget *lgen;

  

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "مولد RSA");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),0);
    
    
      lgen=gtk_label_new("إضغظ ولّد لتوليد المفاتيح");
    
    vbox = gtk_vbox_new(FALSE, 10);
    
	gen=gtk_button_new_with_label("ولّد");
	
	
    
     gtk_box_pack_start(GTK_BOX(vbox),lgen,TRUE,FALSE,5);

  
    gtk_box_pack_start(GTK_BOX(vbox),gen,TRUE,FALSE,5);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    g_signal_connect(G_OBJECT(gen),"clicked",G_CALLBACK(calcul),lgen);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void calcul(GtkButton *button, GtkWidget *gen)
{
	
	
int n,p,q,e,fi,y;





	srand(time(NULL));


	p=q=e=4;
	
	
	while (isprimer(p)!=1)
 	{
 		p=Random(20,100);
 	}
 	while ((isprimer(q)!=1))
 	{
 		q=Random(20,100);
 	}

	n=p*q;

	fi=(p-1)*(q-1);	
	
	y=0;
	while (y==0)
 	{

 		e=Random(2,fi-1);
 		if(pgcd(fi,e)==1){
 			if(isprimer(e)==1){
 				y=1;

 			}
 		} 
 				
 	}      
      


	srand(time(NULL));

	
	
	
GtkWidget *dialog;

dialog = gtk_message_dialog_new(NULL,
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"تم توليد المفاتيح بنجاح!\n n=%d, e=%d, fi=%d. ",n,e,fi);

gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);


	
	
}	



int Random (int iMin, int iMax) 
{ 
return (iMin + (rand () % (iMax-iMin+1))); 
} 

int pgcd(int a,int b)
{
	int r,p;
	r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;

	}
	if(b==1){
		p=1;
	}
	else{
		p=0;
	} 

return p;
}

int isprimer(int t){
int a,i,p,r; 

	a=t;
	for(i=2;i<=a/2;i++){
		r=a%i;
		if (r==0)
		{
			p=0;
			break;
		}
	}

	if (r==0)
	{
		p=0;
	}
	else{
		p=1;
	}
	
	return(p);
}




	



