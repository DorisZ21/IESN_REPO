package tournois;

public class Rencontre {
    private Equipe equipeLocale;
    private Equipe equipeDesVisiteurs;
    private int nbPointsLocaux;
    private int nbPointsVisiteurs;
    private int nbFautesLocaux;
    private int nbFautesVisiteurs;
    private Arbitre arbitre;

    Rencontre(Equipe equipeLocale, Equipe equipeDesVisiteurs, int nbPointsLocaux, int nbPointsVisiteurs,
                int nbFautesLocaux, int nbFautesVisiteurs,Arbitre arbitre){

        this.equipeLocale = equipeLocale;
        this.equipeDesVisiteurs = equipeDesVisiteurs;
        setNbPointsLocaux(nbPointsLocaux);
        setNbPointsVisiteurs(nbPointsVisiteurs);
        setNbFautesLocaux(nbFautesLocaux);
        setNbFautesVisiteurs(nbFautesVisiteurs);
        this.arbitre = arbitre;
    }

    Rencontre(Equipe equipeLocale,Equipe equipeDesVisiteurs,Arbitre arbitre){
        this(equipeLocale,equipeDesVisiteurs,0,0,0,0,arbitre);
    }

    private int estPositif(int valeur){
        if(valeur < 0){
            return 0;
        }else {
            return valeur;
        }
    }

    public void setNbPointsLocaux(int nbPointsLocaux){
       this.nbPointsLocaux = estPositif(nbPointsLocaux);
    }

    public void setNbPointsVisiteurs(int nbPointsVisiteurs){
       this.nbPointsVisiteurs = estPositif(nbPointsVisiteurs);
    }

    public void setNbFautesLocaux(int nbFautesLocaux){
        this.nbFautesLocaux = estPositif(nbFautesLocaux);
    }

    public void setNbFautesVisiteurs(int nbFautesVisiteurs){
        this.nbFautesVisiteurs = estPositif(nbFautesVisiteurs);
    }

    // Surcharge des méthodes
    public void ajouterPointsAuxLocaux(int nbPoints){
        this.nbPointsLocaux += nbPoints;
    }

    public void ajouterPointsAUxVisiteurs(int nbPoints){
        this.nbPointsVisiteurs += nbPoints;
    }
    public void ajouterPointsAuxLocaux(){
        ajouterPointsAuxLocaux(1);
    }

    public void ajouterPointsAuxVisiteurs(){
        ajouterPointsAUxVisiteurs(1);
    }

    public void ajouterFauteAuxLocaux(){
        this.nbFautesLocaux++;
    }

    public void ajouterFauteAuxVisiteurs(){
        this.nbFautesVisiteurs++;
    }

    public boolean exAequo(int premierValeur,int deuxiemeValeur){
        return premierValeur == deuxiemeValeur;
    }

    public String vainqueur(){
        if(exAequo(this.nbPointsLocaux,this.nbPointsVisiteurs)){
            return "ex aequo";
        } else if (nbPointsLocaux > nbPointsVisiteurs) {
            return equipeLocale.getNom();
        }else {
            return equipeDesVisiteurs.getNom();
        }
    }

    public String equipeFairPlay(){
        if(exAequo(this.nbFautesLocaux,this.nbFautesVisiteurs)){
            return "ex aequo";
        } else if (this.nbFautesLocaux < this.nbFautesVisiteurs) {
            return this.equipeLocale.getNom();
            
        }else{
            return this.equipeDesVisiteurs.getNom();
        }
    }

    public String presentationLocaux(){
        return "Equipe locale " + equipeLocale.getNom();
    }

    public String presentationVisiteurs(){
        return "Equipe des visiteurs " + equipeDesVisiteurs.getNom();
    }




}
