package jp.ac.nitech.hook;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class HookLoadJNIActivity extends Activity implements OnClickListener {

	private TextView retTextView;
	private Button addButton;

	static {
		System.loadLibrary("HookSample");
	}
	public native void printJNI();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		addButton = (Button)findViewById(R.id.addButton);
		addButton.setOnClickListener(this);
		retTextView = (TextView)findViewById(R.id.retTextView); 
	}

	@Override
	public void onClick(View v) {
		Log.d("HookLoadJNIActivity","Click");
		printJNI();
	}
}
