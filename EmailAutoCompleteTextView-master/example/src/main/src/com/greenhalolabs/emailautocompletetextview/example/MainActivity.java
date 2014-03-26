package com.greenhalolabs.emailautocompletetextview.example;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.ViewGroup;
import com.greenhalolabs.emailautocompletetextview.EmailAutoCompleteTextView;

public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EmailAutoCompleteTextView emailAutoCompleteTextView = new EmailAutoCompleteTextView(this);
        emailAutoCompleteTextView.setHint(R.string.enter_an_email);
        emailAutoCompleteTextView.setClearButtonEnabled(false);

        final ViewGroup container = (ViewGroup) findViewById(R.id.container);
        container.addView(emailAutoCompleteTextView);
    }

}
