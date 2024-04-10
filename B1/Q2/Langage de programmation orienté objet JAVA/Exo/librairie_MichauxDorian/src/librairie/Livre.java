package librairie;

public class Livre {
    private String isbn;
    private String titre;
    private String langue;
    private int nbPages;
    private double coutBase;
    private double reductionBoursier;
    private Editeur editeur;

    Livre(String isbn,String titre, String langue,int nbPages,double coutBase,double reductionBoursier, Editeur editeur){
        this.isbn = isbn;
        this.titre = titre;
        this.langue = langue;
        setNbPages(nbPages);
        this.coutBase = coutBase;
        this.reductionBoursier = reductionBoursier;
        setEditeur(editeur);
    }

    Livre(String isbn,String titre,int nbPages,double coutBase, double reductionBoursier, Editeur editeur){
        this(isbn,titre,"Français",nbPages,coutBase,reductionBoursier,editeur);
    }

    public double getCoutBase(){
        return this.coutBase;
    }

    public double getReductionBoursier(){
        return this.reductionBoursier;
    }

    public String getTitre(){
        return this.titre;
    }

    public Editeur getEditeur(){
        return this.editeur;
    }

    public void setNbPages(int nbPages){
        if(nbPages < 1){
            if(this.nbPages == 0){
                this.nbPages = 1;
            }
        }else{
            this.nbPages = nbPages;
        }
    }

    public void setEditeur(Editeur editeur){
        this.editeur = editeur;
    }

    public boolean publicationAcademique(){
        if(editeur.getCategorie() == "universitaire"){
            return true;
        }else{
            return false;
        }
    }

    public String toString(){
        return "le livre de " + this.nbPages + " pages intitulé " + this.titre + " (isbn : " + this.isbn + ") édité en "
                + this.langue + " par " + editeur;
    }

}
