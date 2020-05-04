<div dir="rtl">

# تعریف و کاربرد Parity Checking & CRC :  

**بیت Parity یا بیت توازن چیست؟** <br/>

بیت توازن در اصل مقداری است که برای استفاده و چک کردن مقادیر ارسال ایجاد شده است برای مثال ما فایلی را از جایی به جای دیگر منتقل می کنیم تمامی این اطلاعات همراه با یک بیت توازن است تا اگر خطایی رخ داد در برنامه مشخص شود.

**بیت توازن دو نوع دارد :** <br/><br/>

* **نوع اول بیت توازن زوج :**

  * اگر مقادیر ما همه یک های آن یک عدد فرد باشد بیت توازن  یک می شود تا مقدار را زوج کند اما اگر تمامی یک های داده ما زوج باشد بیت توازن تبدیل به صفر می شود.

* **نوع دوم بیت توازن فرد :**
  * بیت توازن فرد هم همانند بیت توازن زوج می باشد به این صورت که اگر جمع همه مقادیر یک های ما یک عدد زوج باشد بیت توازن یک می شود و با جمع شدن آن جمع همه مقادیر یک تبدیل به یک عدد فرد می شود در غیر اینصورت اگر جمع همه یک ها عدد فرد باشد بیت توازن ما صفر می شود.

## مثال :
* دو کامپیوتر شخصی را فرض کنید که قرار است اطلاعات از کامپیوتر یک به کامپیوتر دو منتقل شود حال در وسط راه دچار مشکل می شویم و از بیت های زوج ما یک رقم کم می شود وقتی یک رقم کم شود بیت توازن ما روشن می شود در اصل ما اینجا در حال استفاده از بیت توازن زوج هستیم چرا که داریم مقدار را زوج می کنیم در کامپیوتر دو وقتی بیت توازن را چک کند و ببیند مقدار آن تبدیل به یک شده است و داده ما فرد است کامپیوتر دوم به ما خطا بر می گرداند البته لازم به ذکر است که از این روش برای سازمان های بزرگ که اطلاعات مهم است استفاده نمی شود در اصل در سازمان های بزرگ بیت توازن ۳ بیت است تا اگر در انتقال فایل ها خطایی رخ داد متوجه آن بشوند چرا که در روش اول ممکن است بعضی وقت ها بیت توازن خروجی درستی ندهد و سیستم به اشتباه بیوفتد اما در روش بعدی که سازمان ها استفاده می کنند از این مشکل پیشگیری می کنند.

**پریتی و رید کردن :**

* تکنیک parity  در آرایه افزونه دیسک های مستقل یا RAID نیز استفاده می شود. RAID Controller ها فرم های پیشرفته تشخیص خطای parity را مانند پریتی افقی یا عمودی به کار می برند. بعضی از انواع RAID – مثل RAID 4 یا RAID 5 – یک یا دو دیسک را به عنوان دیسک پریتی در نظر می گیرند که می تواند داده ها را بعد از خرابی یکی از دیسک ها دوباره بازسازی کند. به عنوان مثال رید پریتی دوتایی (که با نام RAID 6 هم شناخته می شود) داده ها را برای حداقل چهار دیسک درسطح block-level نوار بندی می کند، مثل RAID 5، اما یک دسته اطلاعات دیگر را به عنوان پریتی دوم می سازد که در طول درایوها پخش می شود. این روش امکان بازیابی اطلاعات پس از خرابی دو دیسک را فراهم می سازد. هرچند RAID با دو پریتی نیازمند کنترلر پیچیده، هزینه بیشتر به دلیل دو درایو اضافه و سرعت نوشتن پایین تر است.

## یک مثال برای چگونگی دریافت و تصحیح خطا :
**تک parity :** </br>

* **فرض کنید چهار رشته چهار بیتی اطلاعات به شرح زیر است:**

<div dir="ltr">
![ImageLink1](https://rasamserver.com/wp-content/uploads/2019/08/2019-08-20_134644.jpg)

| XOR  | Y  | X  |
|---|---|---|
| 0  | 0  | 0  |
| 1  | 1  | 0  |
| 1  | 0  | 1  |
| 0  | 1  | 1  |

</div>

</div>
