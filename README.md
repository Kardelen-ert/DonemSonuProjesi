Bu projede, C++ dilinde çalışma sırasında boyutu değişebilen bir dizi yapısı geliştirilmiştir. Sabit boyutlu diziler, eleman sayısının önceden bilinmediği durumlarda yetersiz kaldığı için bu projede dinamik bellek kullanan bir çözüm tercih edilmiştir. Bu amaçla önce temel bir DynamicArray sınıfı oluşturulmuş, ardından bu sınıf kullanılarak SortedArray ve UniqueArray sınıfları geliştirilmiştir. Projede amaç yalnızca çalışan bir kod yazmak değil, aynı zamanda düzenli, anlaşılır ve tekrar kullanılabilir bir yapı oluşturmaktır.

DynamicArray sınıfı, elemanları dinamik olarak ayrılan bir bellek alanında tutmaktadır. Dizi dolduğunda kapasite otomatik olarak artırılmakta ve mevcut elemanlar yeni alana kopyalanmaktadır. Bu yöntem, her eklemede yeni bellek ayırmayı önleyerek daha verimli bir çalışma sağlar. Dizi içindeki eleman sayısı ile ayrılan bellek miktarı ayrı değişkenler ile tutulmuş, böylece dizinin durumu kolayca kontrol edilebilir hale getirilmiştir.

Sınıf içinde dinamik bellek kullanıldığı için kopyalama ve silme işlemlerinin doğru şekilde yapılması önemlidir. Bu nedenle kopya kurucu, yıkıcı fonksiyon ve atama operatörü tanımlanmıştır. Bu sayede nesneler kopyalandığında bellek hatalarının oluşması engellenmiştir.

DynamicArray sınıfının daha kolay kullanılabilmesi için bazı operatörler tanımlanmıştır. Köşeli parantez operatörü ile dizi elemanlarına doğrudan erişim sağlanmış, iki dizinin birleştirilebilmesi için toplama operatörü kullanılmıştır. Ayrıca dizilerin karşılaştırılabilmesi ve ekrana yazdırılabilmesi mümkün hale getirilmiştir. Bu sayede sınıf, standart dizilere benzer bir kullanım sunmaktadır.

SortedArray sınıfı, DynamicArray sınıfından türetilmiş ve elemanların her zaman sıralı tutulduğu bir yapı olarak tasarlanmıştır. Yeni bir eleman eklenirken, yalnızca gerekli elemanlar kaydırılarak doğru konuma yerleştirme yapılmıştır. Bu yaklaşım, dizinin her eklemeden sonra tekrar sıralanmasını gereksiz hale getirmiştir. Dizi sıralı olduğu için arama işlemleri daha hızlı bir şekilde gerçekleştirilebilmektedir.

UniqueArray sınıfı ise, dizide aynı değerden birden fazla bulunmasını engellemek amacıyla oluşturulmuştur. Eleman eklenmeden önce dizide aynı değer olup olmadığı kontrol edilmekte, eğer değer zaten varsa ekleme işlemi yapılmamaktadır. Bu işlem temel sınıfın yapısı korunarak gerçekleştirilmiştir.

DynamicArray sınıfında eleman ekleme fonksiyonu sanal olarak tanımlanmış, böylece türev sınıflar kendi ekleme kurallarını uygulayabilmiştir. Bu yapı, kodun daha esnek olmasını sağlamış ve ileride yeni dizi türlerinin eklenmesine imkân tanımıştır.

Projenin doğruluğu, main.cpp dosyasında yazılan testler ile kontrol edilmiştir. Her sınıf ayrı ayrı denenmiş ve tüm fonksiyonların doğru şekilde çalıştığı görülmüştür. Sonuç olarak bu projede, C++ dilinde dinamik bellek kullanımı ve sınıf yapıları anlaşılır ve düzenli bir şekilde uygulanmıştır.
