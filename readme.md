# Weather observations
- Reason & ReasonReact client
- Reason & Express server
- [atd](https://atd.readthedocs.io/ ) generated types that are shared between client and server

## Further plans
- Websocket connection that emits new observations when they're added
- Show the observations on map
- Show the latest observation for each city
- Show the min/max during 24 hours for each city

## Instructions
```
Ilmastotieteilijät tarvitsevat uuden web-sovelluksen, jolla voivat seurata säätilan muutoksia ympäri maailmaa.

Saimme heiltä seuraavan toivelistan:
  • Web-sovellukseen ei tarvitse kirjautua sisään
  • Kaikki käyttäjät voivat syöttää lämpötilahavaintoja havaintopisteiltä, joita on 5 kappaletta (katso lista tehtävänannon lopussa)
  • Uusia havaintopisteitä ei tarvitse pystyä lisäämään web-sovelluksen kautta
  • Kirjatut havainnot ovat kaikkien käyttäjien katseltavissa
  • Havainnoista tärkeimmät tiedot ovat:
  • Tämänhetkinen lämpötila jokaisessa havaintopisteessä tuoreimman kirjatun havainnon mukaan
  • Ylin ja alin lämpötila viimeisen 24 tunnin ajalta jokaisessa havaintopisteessä
  • On tutkimuksen kannalta tärkeää, että tallennettavat havainnot ovat valideja
  • On myös tärkeää, että tiedot pysyvät tallessa, vaikka sovelluksesi kaatuisi

Ohjeita tehtävän tekemiseen:
  • Voit olettaa, että tutkijoiden käytössä on moderni web-selain (esimerkiksi Chrome tai Firefox)
  • Kiinnitä huomiota siihen, että koodisi on jaettu järkeviin ja helposti luettaviin kokonaisuuksiin
  • Sovellusta olisi hyvä päästä testaamaan: voit siis laittaa valmiin sovelluksen pyörimään vaikkapa Herokuun
  • Voit toimittaa lähdekoodit meille esimerkiksi linkkinä GitHub-repositorioon, tai ZIP-tiedostona. Liitä mukaan kaikki tehtävän kannalta olennaiset tiedostot.

  Havaintopisteet:

Tokio: 35.6584421,139.7328635
Helsinki: 60.1697530,24.9490830
New York: 40.7406905,-73.9938438
Amsterdam: 52.3650691,4.9040238
Dubai: 25.092535,55.1562243
```
