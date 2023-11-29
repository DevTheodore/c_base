static char** FR;
char** getFR(void) {
    return FR;
}
void initFr(void) {
    FR = malloc(8192);
    FR[0] = ("Français");
    FR[1] = "Langue chargée";
    FR[2] = "Paramètres de ligne de commande : ";
    FR[3] = "Argument @ non reconnu,\nTaper @ @help, pour afficher l'aide.";
    FR[4] = "Paramètres : \n	Afficher l'aide : @\n	Langue sélectionnée : @\n	Afficher Information : @\n	Afficher avertisement : @\n	Considérer les avertisements comme des erreurs : @\n	Enregistrer les journaux : @\n	Afficher les information dans les journaux : @\n	Fichier journal : @\n	Dossier de stockage des fichiers langues : @\n";
    FR[5] = "Oui";
    FR[6] = "Non";
    FR[7] = "Impossible d'ouvrir le fichier langue (Chemin d'accés : @).";
    FR[8] = "Langue non chargée anglais sélectioné.";
    FR[9] = "Rétro-écriture";
    FR[10] = "Information";
    FR[11] = "Avertisement";
    FR[12] = "Erreur";
    FR[13] = "Crash";
    FR[14] = "Démarrage";
    FR[15] = "Impossible d'ouvrir le fichier journal (Chemin d'accés : @).";
    FR[16] = "Arrêt normal";
    FR[17] = "Arrêt d'urgence";
    FR[18] = "Paramétre de langue invalide";
    FR[19] = "Paramétre du chemin du dossier des langes invalide";
    FR[20] = "Paramétre du chemin du fichier jounal invalide";
    FR[21] = "Des anomalies ont été détectées, voulez-vous continuer ? (Oui/Non)";
    FR[22] = "Des paramétres sont invalides voulez vous les rectifier ? (Oui/Non)";
    FR[23] = "Emplacement du fichier journal : ";
    FR[24] = "Emplacement du dossier des langues : ";
    FR[25] = "Nom de la langue (exemple : Francais / fr / FR) : ";
    FR[26] = "Impossible d'écrire dans le fichier journal.";
    FR[27] = "Passage en mode sans journal";
    FR[28] = "Saisie invalide";
    FR[29] = "Message (@) introuvable";
}
