# Calculator (C)

Argüman tabanlı, geçmiş tutan basit hesap makinesi.

## Derleme ve Çalıştırma

```bash
gcc calculator.c -o calculator
./calculator 9 - 4          # => 5
./calculator 5 / 0          # => Hata: Sifira bolme
```

## Kapsam

- Fonksiyonlar ve `static` depolama sınıfı
- `strcmp` ile string karşılaştırma
- `snprintf` ile tampon güvenli yazma
- Bellek/`char[]` kullanımı
- Dönüş kodları ile hata yönetimi
