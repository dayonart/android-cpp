package id.org.dne;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.widget.RelativeLayout;
import android.widget.TextView;

import dalvik.annotation.optimization.FastNative;


public class MainActivity extends Activity {

    @FastNative
    private native RelativeLayout relativeLayout();

    @FastNative
    private native RelativeLayout.LayoutParams relativeParams();

    @FastNative
    private native TextView textView();

    @FastNative
    private native String getString(); //String is not data type

    @FastNative
    private native int getInt();

    @FastNative
    private native String getBool();    //Boolean is not data type


    private final int age = 10;

    static {
        System.loadLibrary("dne");
    }


    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        RelativeLayout.LayoutParams textParams = relativeParams();
        RelativeLayout relativeLayout = relativeLayout();
        TextView textView = textView();
        textView.setLayoutParams(textParams);
        textView.setText(getString() + "\n" + getInt() + "\n" + Boolean.valueOf(getBool()));
        textView.setTextColor(Color.GREEN);
        relativeLayout.addView(textView);
        setContentView(relativeLayout);
    }
}