<div dir="rtl">

# تعریف و کاربرد Parity Checking & CRC :  

**الگوریتم CRC**

***Cyclic Redundancy Check***

کد افزونگی چرخشی، توسط وزلی پترسون در سال 1961 به ثبت رسید. این مجموعه کد به منظور یافتن تغییرات ناگهانی در داده های در حال جابه جایی در شبکه های مخابراتی و یا دسنگاه های ذخیره سازی، مورد استفاده قرار می گیرد.

CRC در بردارنده تقسیمات دودویی از بیت های داده ای است که با توافق سیستم ارتباطی ارسال می شود. تقسیم  کننده با استفاده از روابط چند جمله ای تولید می شوند. بنابراین، CRC نیز به عنوان یک مجموعه مقابله ای کد چند جمله ای شناخته می شود.

پیش از اینکه پیام توسط رسانه انتقال فرستاده شود، فرستنده با استفاده از CRC پیام را رمزنگاری می کند. گیرنده پیام ارسالی را به منظور خطایابی رمزگشایی می کند. اگر خطایی در پیام یافت نشد، مورد قبول واقع خواهد شد، در غیر اینصورت، گیرنده بار دیگر درخواست ارسال مجدد را صادر می کند.

![نحوه کار CRC](https://www.tutorialspoint.com/assets/questions/media/17615/35_1.jpg)

**محاسبات CRC :**

هنگامی که پیام ها با استفاده از CRC (کد چند جمله ای) رمزگذاری می شوند ، از چند جمله ای ثابت  ژنراتور ، <span dir="lrt">G(x)</span> استفاده می شود. ;مقادیرطرفین توسط فرستنده و گیرنده به همسنگ می باشند. کلمه k - bit توسط چند جمله ای نمایش داده می شود که از x<sup>0</sup> تا x<sup>k-1</sup> متغیر است. ترتیب این چند جمله ای قدرت بالاترین ضریب است ، یعنی  طول <span dir="lrt">G(x)</span> باید کمتر از طول پیامی باشد که آن را رمزگذاری می کند. همچنین ، هر دو MSB (مهمترین بیت آن) و LSB (حداقل بیت قابل توجهی) باید 1 باشند. در فرآیند رمزگذاری ، بیت های CRC به پیام پیوست می شوند تا قاب نتیجه با <span dir="lrt">G(x)</span> قابل تقسیم باشد.

## مثال 1 (بدون خطا) :

```
داده ای ارسال می شود : 100100
کلید - 1101 [یا چند جمله ای (x^3)+(x^2)+1]
فرستنده :
```
![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/rational1.jpg)
```
در هر صورت، reminder برابر با 001 می باشد و باید رمزگذاری شود.
داده ارسال شده 100100001 می باشد.

گیرنده :
کدی که در سمت گیرنده دریافت می شود 100100001 می باشد.
```
![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/rational2.jpg)
```
با این حال، reminder برابر با صفر می شود و بنابراین داده دریافت شده بدون خطا بوده است.
```

[کد پیاده سازی CRC در c++](https://github.com/omidnw/CRC-ParityChecking/blob/master/CRC.cpp)

<br/><br/><br/>

**بیت Parity یا بیت توازن چیست؟** <br/>

بیت توازن در اصل مقداری است که برای استفاده و چک کردن مقادیر ارسال ایجاد شده است برای مثال ما فایلی را از جایی به جای دیگر منتقل می کنیم تمامی این اطلاعات همراه با یک بیت توازن است تا اگر خطایی رخ داد در برنامه مشخص شود.

**بیت توازن دو نوع دارد :** <br/><br/>

* **نوع اول بیت توازن زوج :**

  * اگر مقادیر ما همه یک های آن یک عدد فرد باشد بیت توازن  یک می شود تا مقدار را زوج کند اما اگر تمامی یک های داده ما زوج باشد بیت توازن تبدیل به صفر می شود.

* **نوع دوم بیت توازن فرد :**
  * بیت توازن فرد هم همانند بیت توازن زوج می باشد به این صورت که اگر جمع همه مقادیر یک های ما یک عدد زوج باشد بیت توازن یک می شود و با جمع شدن آن جمع همه مقادیر یک تبدیل به یک عدد فرد می شود در غیر اینصورت اگر جمع همه یک ها عدد فرد باشد بیت توازن ما صفر می شود.

## مثال :
* **دو کامپیوتر شخصی را فرض کنید که قرار است اطلاعات از کامپیوتر یک به کامپیوتر دو منتقل شود حال در وسط راه دچار مشکل می شویم و از بیت های زوج ما یک رقم کم می شود وقتی یک رقم کم شود بیت توازن ما روشن می شود در اصل ما اینجا در حال استفاده از بیت توازن زوج هستیم چرا که داریم مقدار را زوج می کنیم در کامپیوتر دو وقتی بیت توازن را چک کند و ببیند مقدار آن تبدیل به یک شده است و داده ما فرد است کامپیوتر دوم به ما خطا بر می گرداند البته لازم به ذکر است که از این روش برای سازمان های بزرگ که اطلاعات مهم است استفاده نمی شود در اصل در سازمان های بزرگ بیت توازن ۳ بیت است تا اگر در انتقال فایل ها خطایی رخ داد متوجه آن بشوند چرا که در روش اول ممکن است بعضی وقت ها بیت توازن خروجی درستی ندهد و سیستم به اشتباه بیوفتد اما در روش بعدی که سازمان ها استفاده می کنند از این مشکل پیشگیری می کنند.**

**پریتی و رید کردن :**

* تکنیک parity  در آرایه افزونه دیسک های مستقل یا RAID نیز استفاده می شود. RAID Controller ها فرم های پیشرفته تشخیص خطای parity را مانند پریتی افقی یا عمودی به کار می برند. بعضی از انواع RAID – مثل RAID 4 یا RAID 5 – یک یا دو دیسک را به عنوان دیسک پریتی در نظر می گیرند که می تواند داده ها را بعد از خرابی یکی از دیسک ها دوباره بازسازی کند. به عنوان مثال رید پریتی دوتایی (که با نام RAID 6 هم شناخته می شود) داده ها را برای حداقل چهار دیسک درسطح block-level نوار بندی می کند، مثل RAID 5، اما یک دسته اطلاعات دیگر را به عنوان پریتی دوم می سازد که در طول درایوها پخش می شود. این روش امکان بازیابی اطلاعات پس از خرابی دو دیسک را فراهم می سازد. هرچند RAID با دو پریتی نیازمند کنترلر پیچیده، هزینه بیشتر به دلیل دو درایو اضافه و سرعت نوشتن پایین تر است.

## یک مثال برای چگونگی دریافت و تصحیح خطا :
**تک parity :** </br>

* **فرض کنید چهار رشته چهار بیتی اطلاعات به شرح زیر است:** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134644.jpg)

</div>

* **برای ساختن پریتی P به سادگی این چهار رشته را در هم XOR می کنیم.  جدول منطقی عملگر XOR در زیر آمده است :** <br/>

<div dir="ltr">

| XOR  | Y  | X  |
|---|---|---|
| 0  | 0  | 0  |
| 1  | 1  | 0  |
| 1  | 0  | 1  |
| 0  | 1  | 1  |

</div>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134737.jpg)

</div>

* **P در اینجا یک رشته چهاربیتی است و در واقع همان اطلاعات پریتی است. اگر از بین این پنج رشته یکی از بین برود می توان با استفاده از بقیه  اطلاعات آن رشته را بدست آورد. اگر P از بین برورد با همین روش ساخت پریتی می توان آن را دوباره ساخت. اما اگر یکی از اطلاعات اصلی (مثلا D1) از بین برود کافی است باقی رشته ها که شامل P نیز می شود با هم XOR کرد :** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134754.jpg)

</div>

**دو Parity :**

* **برای ساختن پریتی دوم لازم است تا از عملگر Shift برای هر رشته استفاده کرد. تعریف عملگر Shift به شرح زیر است :** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134811.jpg)

</div>

* **استفاده از عملگر Shift یک رشته منحصر بفرد برای هر رشته در اختیار ما قرار می دهد. پریتی دوم به روش زیر محاسبه می شود :** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134827.jpg)

</div>

* **در اینجا در صورتی که یکی از رشته ها از بین برود می توان به راحتی مثل تصحیح خطا در تک پریتی آن را بازسازی کرد. اما در دو پریتی نشان می دهیم در صورتی که دو رشته نیز ازبین برود می توان آنها را بازسازی کرد. اگر رشته P و یکی از رشته های اصلی از بین برود می توان آن رشته را با استفاده از Q و این واقعیت که XOR هر رشته در خودش برابر صفر است بدست آورد. فرض کنید P و D3 از بین رفته باشد. می توان D3 را از این فرمول و در نهایت  با عکس کردن عملگر Shift  محاسبه کرد :** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134839.jpg)

</div>

* **همچنین اگر اطلاعات دو رشته اصلی از بین رفت می توان آنها را با استفاده از P و Q و XOR کردن باقی رشته ها در آنها بدست آورد. فرض کنید D0 و D3 از بین رفته باشد. با استفاده از فرمول زیر می توان به نتیجه رسید :** <br/>

<div dir="ltr">

![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134854.jpg)

</div>

* **این یک دومعادله دومجهولی در سطح بیت است که با حل کردن آن می توان دو جواب منحصر به فرد برای D0 و D3 بدست آورد.**

**منابع :** <br/><br/>
- [رسام سرور.][RasamServer]

- [TutorialsPoint][TutorialsPoint]

- [GeeksforGeeks][GeeksforGeeks]

- [WikiPedia][WikiPedia]


>[آریا خوشنود][GithubAriakh55] - [امید رضا کشتکار][Githubomidnw].

[RasamServer]: https://rasamserver.com/

[GithubAriakh55]: https://github.com/ariakh55/

[Githubomidnw]: https://github.com/omidnw/

[TutorialsPoint]: [https://www.tutorialspoint.com/what-is-algorithm-for-computing-the-crc]

[GeeksforGeeks]: [https://www.geeksforgeeks.org/modulo-2-binary-division/]

[WikiPedia]: [https://en.wikipedia.org/wiki/Cyclic_redundancy_check]

</div>
