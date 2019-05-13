void detectar_Cor() {
  sensor_Detectado = 1;
  lcd.setCursor(0, 0);
  lcd.print("Detectando cor       ");
  lcd.setCursor(0, 1);
  lcd.print("Aguarde...       ");
  int Vetor_Cores[10];
  for (int i = 0; i < 10; i++) {
    pixels.setPixelColor(0, 255, 0, 0); // Vermelho
    pixels.show(); // Mostra os pixels
    delay(30);
    ldrValor_Vermelho = analogRead(ldrPin); //Lê o valor do LDR (entre 0 e 1023)
    delay(30);
    pixels.setPixelColor(0, 0, 255, 0); // Verde
    pixels.show(); // Mostra os pixels
    delay(30);
    ldrValor_Verde = analogRead(ldrPin); //Lê o valor do LDR (entre 0 e 1023)
    delay(30);
    pixels.setPixelColor(0, 0, 0, 255); // Azul
    pixels.show(); // Mostra os pixels
    delay(30);
    ldrValor_Azul = analogRead(ldrPin); //Lê o valor do LDR (entre 0 e 1023)
    delay(30);
    // Analise de dados
    Serial.print("Vermelho = ");
    Serial.println(ldrValor_Vermelho);
    Serial.print("Verde = ");
    Serial.println(ldrValor_Verde);
    Serial.print("Azul = ");
    Serial.println(ldrValor_Azul);

    if ((ldrValor_Vermelho < 430) && (ldrValor_Verde > 735) && (ldrValor_Azul > 800)) {
      Vetor_Cores[i] = 1;
    }
    else if ((ldrValor_Vermelho > 600) && (ldrValor_Verde > 750) && (ldrValor_Azul < 800)) {
      Vetor_Cores[i] = 2;
    }
    else if ((ldrValor_Vermelho > 430) && (ldrValor_Verde < 700) && (ldrValor_Azul > 700)) {
      Vetor_Cores[i] = 3;
    }
    else if ((ldrValor_Vermelho > 700) && (ldrValor_Verde > 800) && (ldrValor_Azul > 800)) {
      Vetor_Cores[i] = 4;
    }
    else {
      Vetor_Cores[i] = 0;
    }
  }
  Cor_Detectada = vetor_Comum(Vetor_Cores);
  for (int i = 0; i < 10; i++) { // Utilizado para analise de dados
    Serial.print(i);
    Serial.print(" - Leitura");
    Serial.println(Vetor_Cores[i]);
  }
  sensor_Detectado = 0;
}
