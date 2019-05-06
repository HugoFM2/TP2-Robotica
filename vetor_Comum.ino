int vetor_Comum(int Vetor[]) { // Pega o valor mais comum em um array
  int Cor_Detectada_Final;
  int count_Vermelho = 0;
  int count_Verde = 0;
  int count_Azul = 0;
  int count_Preto = 0;

  for (int i = 0; i < 10; i++) {
    if (Vetor[i] == 1) {
      count_Vermelho++;
    }
    if (Vetor[i] == 2) {
      count_Azul++;
    }
    if (Vetor[i] == 3) {
      count_Verde++;
    }
    if (Vetor[i] == 4) {
      count_Preto++;
    }
  }

  if ((count_Vermelho > count_Verde) && (count_Vermelho > count_Azul) && (count_Vermelho > count_Preto)) {
    Cor_Detectada_Final = 1;
    lcd.setCursor(0, 1);
    lcd.print("Vermelho       ");
  }
  else if ((count_Azul > count_Verde) && (count_Azul > count_Vermelho) && (count_Azul > count_Preto)) {
    Cor_Detectada_Final = 2;
    lcd.setCursor(0, 1);
    lcd.print("Azul       ");
  }
  else if ((count_Verde > count_Vermelho) && (count_Verde > count_Azul) && (count_Verde > count_Preto)) {
    Cor_Detectada_Final = 3;
    lcd.setCursor(0, 1);
    lcd.print("Verde        ");
  }
  else if ((count_Preto > count_Verde) && (count_Preto > count_Vermelho) && (count_Preto > count_Azul)) {
    Cor_Detectada_Final = 4;
    lcd.setCursor(0, 1);
    lcd.print("Preto       ");
  }
  return Cor_Detectada_Final;
}
