#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include <string.h>


typedef struct _bina
{
     GtkWidget *n;
     GtkWidget *e;
     GtkWidget *fi;
     GtkWidget *bin;
     
}bina;


int inverse(int en,int f);
void calcul(GtkButton *button,bina *oka);

gboolean fin(GtkWidget *widget, GdkEvent *event, gpointer user_data);


int main(int argc, char *argv[])
{
    GtkWidget *window; GtkWidget *vbox; GtkWidget *enc; 
    
    GtkWidget *bin, *scrolled;
    GtkWidget *n, *e, *fi;
    GtkWidget *en, *ee, *efi;
    GtkWidget *hbox1, *hbox2, *hbox3;
    
    
  

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "معدل RSA");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),0);


bin=gtk_text_view_new();

 
    en = gtk_label_new("أدخل n:");
    ee = gtk_label_new("أدخل e:");
    efi = gtk_label_new("أدخل fi:");
    n = gtk_entry_new();
    e = gtk_entry_new();
    fi = gtk_entry_new();
    
      hbox1 = gtk_hbox_new(TRUE, 5);
      hbox2 = gtk_hbox_new(TRUE, 5);
      hbox3 = gtk_hbox_new(TRUE, 5);
    
	gtk_entry_set_visibility(GTK_ENTRY(fi), FALSE);

    vbox = gtk_vbox_new(FALSE, 10);
    
    enc=gtk_button_new_with_label("تعديل");


    gtk_box_pack_start(GTK_BOX(hbox1), n, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox1), en, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox2), e, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox2), ee, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox3), fi, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox3), efi, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 5);

	scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_box_pack_start(GTK_BOX(vbox), scrolled, TRUE, TRUE, 5);
	gtk_container_add(GTK_CONTAINER(scrolled), bin);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),
	GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  
    gtk_box_pack_start(GTK_BOX(vbox),enc,TRUE,FALSE,5);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    
     bina *data = malloc(sizeof(*data));
data->n = n;
data->e = e;
data->fi = fi;
data->bin = bin;

    g_signal_connect(G_OBJECT(enc),"clicked",G_CALLBACK(calcul),data);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

int inverse(int en,int f){
	int a,b,u,v,q,r,l,k;
	a=f; b=en;
	u=0;v=1; q=(a/b); r=(a%b);
	while (r!=0){
		l=v; k=(u-(v*q)); u=l; v=k; a=b; b=r; q=(a/b); r=(a%b);
	}
	k=(k+f)%f;return k;
}

void calcul(GtkButton *button, bina *oka)
{

int j,d,y,k;

int base,m,res,jj; int puis,bit;


char  lnp[10000];
int  plan[10000];
char  cypher[10000];
char  pln[10000];

GtkTextBuffer* text_buffer=0;
GtkTextIter start;
GtkTextIter end;
gchar* buf=0;



	


//On recupere le buffer
text_buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(oka->bin));
//On recupere l'origine du buffer
gtk_text_buffer_get_start_iter(text_buffer,&start);
//On recupere la fin du buffer
gtk_text_buffer_get_end_iter(text_buffer,&end);

//On copie le contenu du buffer dans une variable
buf=gtk_text_buffer_get_text(text_buffer,&start, &end,TRUE);
 
 const gchar *    en=gtk_entry_get_text                  (GTK_ENTRY(oka->n));
 guint16            a= gtk_entry_get_text_length(GTK_ENTRY(oka->n));
 
 	
int o=1; int i=a-1; int t=0; 
	while(i>=0)
	{
		t=((((int)en[i])-48)*o)+t;	
		
		o=o*10;
		i--;
		
	}

int n=t;


 const gchar *    eo=gtk_entry_get_text                  (GTK_ENTRY(oka->e));
           a= gtk_entry_get_text_length(GTK_ENTRY(oka->e));
 
 	
o=1; i=a-1; t=0; 
	while(i>=0)
	{
		t=((((int)eo[i])-48)*o)+t;	
		
		o=o*10;
		i--;
		
	}

int e=t;

 const gchar *    efi=gtk_entry_get_text                  (GTK_ENTRY(oka->fi));
           a= gtk_entry_get_text_length(GTK_ENTRY(oka->fi));
 
 	
o=1; i=a-1; t=0; 
	while(i>=0)
	{
		t=((((int)efi[i])-48)*o)+t;	
		
		o=o*10;
		i--;
		
	}

int fi=t;


	d=inverse(e,fi);


FILE * plan_text=fopen("معدل.txt","w+");

	int * ptr = (int *) (& puis) ;
    




 int aa=strlen(buf);  buf[aa]='.'; aa=strlen(buf);
j=aa-2;
i=0;
while(buf[i]!='.')
{
	cypher[j]=buf[i];
	j--;
	i++;

}

cypher[i]=buf[i];

y=0;
    i=0;
    k=0;
while(cypher[k]!='.')
{
	y=0;
	j=k;
	while (j<k+32)
	{
		
		if (cypher[j] == '1')
			y= y * 2 + 1;
		else if (cypher[j] == '0')
			y*= 2;
		j++;
	}
	k=j;
	plan[i]=y;
	i++;
	
}


plan[i]=111111;
	

o=111111;

k=0;
while(plan[k]!=o)	
		{
			

m=(int)plan[k];

 	base=m;
 	puis=d;
 	res=1;
 	bit=1;

	ptr = (int *) (& puis) ;
    
   
      
      jj=n;

      while(puis!=0){


      		bit=(puis & 1);
      		if(bit==1){
      			res=res*base;
      			res= res % jj;
      		}

      		
   			*ptr >>= 1 ;
   			base=base*base;
   			base= base % jj;



      }

			y=(int)res%(int)jj;
			pln[i]=(char)y;
			
			i++;
			k++;

		}

pln[i]='.';

j=i-1;
i=0;
while(pln[i]!='.')
{
	lnp[j]=pln[i];
	i++;
	j--;
}
lnp[i]='.';


i=0;
while(lnp[i]!='.')
{
	
	putc((char)lnp[i],plan_text);
	i++;
}



	
GtkWidget *dialog;




//On affiche le texte dans une boite de dialogue.
dialog = gtk_message_dialog_new(NULL,
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"تمت عملية التعديل بنجاح! \n اسم الملف: معدل.txt  ");

gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);


	
	
}	

