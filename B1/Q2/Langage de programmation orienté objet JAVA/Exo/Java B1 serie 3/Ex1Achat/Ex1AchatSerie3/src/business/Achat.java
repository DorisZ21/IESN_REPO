package business;

public class Achat {
    private int nbExemplaires;
    private Client client;
    private Article article;

    Achat(int nbExemplaires, Client client, Article article){
        setNbExemplaires(nbExemplaires);
        this.client = client;
        this.article = article;
    }

    Achat(Client client,Article article){
        this(1,client,article);
    }

    public int getNbExemplaires(){
        return this.nbExemplaires;
    }

    public Client getClient(){
        return this.client;
    }

    public Article getArticle(){
        return this.article;
    }

    public void setNbExemplaires(int nbExemplaires){
        if(nbExemplaires > 0){
            this.nbExemplaires = nbExemplaires;
        }else{
            this.nbExemplaires = 1;
        }
    }

    public void setClient(Client client){
        this.client = client;
    }

    public String toString(){
       if(this.nbExemplaires == 1){
           return "Le client " + this.client + " a acheté l'article " + this.article + " en un seul exemplaire pour un montant total de "
                   + coutTotal() + " euros.";
       }else {
           return "Le client " + this.client + " a acheté l'article " + this.article + " en "+ this.nbExemplaires + " exemplaires pour un montant total de "
                   + coutTotal() + " euros.";
       }
    }

    public double coutTotal(){
        return this.nbExemplaires * this.article.getPrix();
    }

}
