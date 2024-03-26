package premierPackage;

public class Rectangle {
    private int coordonneeX;
    private int coordonneeY;
    private int largeur;
    private int hauteur;

    Rectangle(int coordoneeX, int coordonneeY, int largeur, int hauteur){
        this.coordonneeX = coordoneeX;
        this.coordonneeY = coordonneeY;
        this.largeur = largeur;
        this.hauteur = hauteur;
    }

    public int getCoordonneeX(){
        return coordonneeX;
    }

    public int getCoordonneeY(){
        return coordonneeY;
    }

    public int getLargeur(){
        return  largeur;
    }


    public int getHauteur(){
        return hauteur;
    }

    public int perimetre(){
        return 2*(largeur + hauteur);
    }

    public int surface(){
        return largeur * hauteur;
    }

    public void modifierLargeur(int newLargeur){
        largeur = newLargeur;
    }

    public void modifierHauteur(int newHauteur){
        hauteur = newHauteur;
    }

    public void deplacerEn(int newX, int newY){
        coordonneeX = newX;
        coordonneeY = newY;
    }


}
