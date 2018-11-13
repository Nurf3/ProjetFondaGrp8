void coeur()
{
  //
  for (int i = 2; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }
  //
  int i = 2;
  int tour;
  //
  int choixUtilisateur = 5;
  int coeurs = 1;
  //
  switch (choixUtilisateur)
  {
  case 1:
    allum(1, coeurs);
    break;

  case 2:
    allum(2, coeurs);
    break;

  case 3:
    allum(3, coeurs);
    break;

  case 4:
    i = 0;
    tour = 1;
    while (coeurs == 1)
    {
      if (tour == 1)
      {
        if (i <= 11)
        {
          digitalWrite(i, HIGH);
          tour = 0;
        }
        else
          i = 0;
      }
    }
    digitalWrite(i, LOW);
    i++;
    tour = 1;

  case 5:
    i = 2;
    int j = 3;
    tour = 1;
    while (coeurs == 1)
    {
      if (tour == 1)
      {
        if (i <= 11 && j <= 11)
        {
          digitalWrite(i, HIGH);
          digitalWrite(j, HIGH);
          delay(100);
          digitalWrite(i, LOW);
          i++;
          j++;
          tour = 0;
        }
      }
      tour = 1;
    }
  }
}

int allum(int Nombre, int coeurs)
{
  int i = 2;

  while (coeurs == 1)
  {
    if (i <= 11)
    {
      digitalWrite(i, HIGH);
      i += Nombre;
    }
  }
  for (int i = 2; i <= 11; i++)
  {
    digitalWrite(i, LOW);
  }
}
