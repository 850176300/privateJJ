EmailAutoCompleteTextView
=========================

EmailAutoCompleteTextView inherits from [AutoCompleteTextView][4] and uses the unique emails associated with the device to provide auto-complete functionality for email input fields. It also provides an "x" button on the right hand side as an easy way to clear text. 

![EmailAutoCompleteTextView Screenshot][1]

**NOTE**: since this view uses [AccountManager][2] to get the emails on the device, you must include the following in your `AndroidManifest.xml`:

```
  <uses-permission android:name="android.permission.GET_ACCOUNTS"/>
```

Please view the sample application under [example/][3] for more details.


## Including EmailAutoCompleteTextView using Gradle:

Add the following to your `build.gradle`:

```
	repositories {
    	mavenCentral()
	}
	dependencies {
		'com.greenhalolabs:emailautocompletetextview:1.2.0'
	}
```

## Usage:

### In XML:

```
<com.greenhalolabs.emailautocompletetextview.EmailAutoCompleteTextView
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:dropDownSelector="@drawable/some_drawable"
    android:hint="@string/enter_an_email"
    android:imeActionLabel="@string/sign_up"
    app:clearButtonDrawable="@drawable/close" />
```

### Programmatically:

```
EmailAutoCompleteTextView emailAutoCompleteTextView = new EmailAutoCompleteTextView(context);
emailAutoCompleteTextView.setHint(R.string.enter_an_email);
emailAutoCompleteTextView.setClearButtonEnabled(true); // defaults to true
emailAutoCompleteTextView.setClearButtonResId(R.drawable.close);
```

### Styling:

Since EmailAutoCompleteTextView inherits from [AutoCompleteTextView][4], styling is similar to styling an AutoCompleteTextView. The drop down item layout used is `android.R.layout.simple_dropdown_item_1line`, to provide a custom styling for this, add the following to your application theme: 

```
<item name="android:dropDownItemStyle">@style/CustomStyle</item>
```


[1]: https://raw.github.com/greenhalolabs/EmailAutoCompleteTextView/master/images/EmailAutoCompleteTextView_demo.gif
[2]: http://developer.android.com/reference/android/accounts/AccountManager.html
[3]: https://github.com/greenhalolabs/EmailAutoCompleteTextView/tree/master/example
[4]: http://developer.android.com/reference/android/widget/AutoCompleteTextView.html
